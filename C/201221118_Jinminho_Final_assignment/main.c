#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FLUSH while(getchar()!='\n')

/* Blackjack 201221118 미디어학과 진민호
  2015/06/03 ~~ 2015/06/14  블랙잭 만들기 */

enum { Num_of_Deck = 52, lose = -1 , Draw = 0, Win = 1, Bust = 50, Blackjack = 100 , firstBlackjack = 200};     // 승패를 판별하기 위해 각각의 상황에 이름을 붙였습니다. 숫자에 큰 의미는 없습니다.
enum { H, C, S, D }; // H : HEART , C : CLOVER , S : SPADE , D : DIAMOND

typedef struct { int Suit; int Number; }CARD;
typedef struct { int Money; int Wins; int loss; int draws; CARD* player_cards; }PLAYER;
typedef struct { int Wins; int loss; int draws; CARD* dealer_cards; }DEALER;

CARD* initDeck();   // 카드의 정보를 구성하는 함수.
void shuffleDeck( CARD* deck ); // 카드를 전부 섞어주는 함수.
CARD* getCard( CARD* deck );    // 카드를 한 장씩 뽑아 주는 함수.
int processPlayer( CARD* player_cards ); // 사용자의 카드뭉치 계산.
int processDealer( CARD* dealer_cards ); // 딜러의 카드뭉치 계산.
void print_card(CARD info); // 카드 정보 출력함수.

CARD* copy_deck;    // getcard에서 사용.  gamedeck에서 값을 받아 저장해 놓고 매개변수 없이도 값을 리턴 할 수 있도록.

int sum_of_score_player = 0;  // 플레이어의 카드의 함.
int sum_of_score_dealer = 0;  // 딜러의 카드의 함.
int first_cycle_process_player = 1; //딜러 카드수행 처음 여부 판별.
int first_cycle_process_dealer = 1; //플레이어 카드수행 처음 여부 판별.
int check_HIT = 0;  //HIT여부 판별
int dealer_card_number = 1; // 딜러가 갖고 있는 카드의 수 /0 부터 계산 (처음 2장 포함하기 때문.)
int player_card_number = 1; // 플레이어가 갖고 있는 카드의 수/ 0 부터 계산 (처음 2장 포함하기 때문.)
int betting_money = 101;    // 배팅할 돈.

int main()
{
    DEALER COMPUTER;
    PLAYER YOU;

    COMPUTER.draws = 0; COMPUTER.Wins = 0; COMPUTER.loss = 0;
    YOU.draws = 0; YOU.Wins = 0; YOU.loss = 0;YOU.Money = 1;
    char finish_option = 'O';
    int score_dealer = 0;   // 딜러의 카드숫자 점수 // 최종으로 승부를 가릴때 사용.
    int score_player = 0;   // 플레이어의 카드숫자 점수 // 최종으로 승부를 가릴때 사용.


    printf("---------------------------------------------------------------------\n");
    printf("\t\t\tLet's play BLACKJACK!!\n");
    printf("---------------------------------------------------------------------\n");
    printf(" ◆♣♥♠게임을 하기에 화면이 작습니다. 화면을 키워 주세요.◆♣♥♠\n\n");
    printf("---------------------------------------------------------------------\n");
    printf("가지고 계신 돈의 액수(5의 배수를 단위로)를 입력해 주세요.\n");
    printf("---------------------------------------------------------------------\n");

    while( (YOU.Money % 5) != 0 ){
        scanf("%d",&YOU.Money);
             printf("조건에 맞게 다시 입력해 주세요.\n");
        if(YOU.Money == 0)
            YOU.Money = 51;     // 0을 입력받았을 시 반복문을 계속 반복하기 위함.
        if( ( ( 0 < YOU.Money ) && (YOU.Money % 5) == 0 ) ) // 반복문조건 안에서 0이 아닌 수를 입력받았을 시 반복문을 빠져나가기 위함.
            break;
        else
            FLUSH;
    }

  while( finish_option != 'N' ){    // finish_option, 갖고있는 돈이 다 떨어지거나 N을 입력 받았을시 게임이 종료됨.

    printf("---------------------------------------------------------------------\n");
    printf("★사용자 정보★\n 승리 : %d 무승부 : %d 패배 : %d 보유 금액 : %d\n",YOU.Wins,YOU.draws,YOU.loss,YOU.Money);
    printf("---------------------------------------------------------------------\n");
    printf("☆딜러 정보☆\n 승리 : %d 무승부 : %d 패배 : %d\n",COMPUTER.Wins,COMPUTER.draws,COMPUTER.loss);
    printf("---------------------------------------------------------------------\n\n\n\n");

    YOU.player_cards = (CARD*)(malloc(8*10)); // 사용자의 카드 덱을 10칸의 공간으로 만듬.
    COMPUTER.dealer_cards = (CARD*)(malloc(8*10));  // 컴퓨터의 카드 덱을 10칸의 공간으로 만듬.

    CARD* gamedeck; // 전체 덱을 구성.
    copy_deck = (CARD*)malloc(8*Num_of_Deck);   //전체 덱에 총 52칸의 카드를 집어넣을 공간을 생성.

    gamedeck = initDeck();  // 전체 덱에 카드의 정보를 구성.

    shuffleDeck(gamedeck);  // 덱을 섞어줌.

    YOU.player_cards[0] = *getCard(gamedeck);
    YOU.player_cards[1] = *getCard(NULL);
    COMPUTER.dealer_cards[0] = *getCard(NULL);
    COMPUTER.dealer_cards[1] = *getCard(NULL);

    printf("====================================================================\n");
    printf("☆딜러☆");
    printf(" 딜러가 공개한 한장의 카드\n");
    print_card( COMPUTER.dealer_cards[0] );

    printf("====================================================================\n\a");
    printf("★사용자★\n");
    printf(" 사용자가 처음 받은 두장의 카드\n");
    print_card( YOU.player_cards[0] );
    print_card( YOU.player_cards[1] );
    printf("배팅할 금액을 입력해 주세요. 마찬가지로 5의 배수단위 입니다.\n");

    while( betting_money % 5 != 0 ){
        scanf("%d",&betting_money );

        if( (50 < betting_money || betting_money < 0) || betting_money % 5 != 0){
            betting_money = 1;
            FLUSH;
            printf("다시 입력해 주세요.\n");
        }
        if( YOU.Money < betting_money ){
            betting_money = 1;
            FLUSH;
            printf("다시 입력해 주세요.\n");
        }
    }

    printf("\n배팅된 금액 : %d\n",betting_money);
    score_player = processPlayer( YOU.player_cards );
    score_dealer = processDealer( COMPUTER.dealer_cards );

    if( calcscore(score_dealer, score_player) == firstBlackjack){
        printf("---------------------------------------------------------------------\n");
        printf("사용자 카드의 합 %d 딜러카드의 합 : %d\n",sum_of_score_player,sum_of_score_dealer);
        printf("Your Blackjack!\n");
        printf("사용자님이 이겼습니다^^\n");
        printf("---------------------------------------------------------------------\n");

        printf("얻은 금액 : %d \n", 3 * betting_money);
        YOU.Money += 3 * betting_money;

        COMPUTER.loss++;
        YOU.Wins++;
    }

    else if( calcscore(score_dealer, score_player) == Blackjack){
        printf("---------------------------------------------------------------------\n");
        printf("사용자 카드의 합 %d 딜러카드의 합 : %d\n",sum_of_score_player,sum_of_score_dealer);
        printf("Your Blackjack!\n");
        printf("사용자님이 이겼습니다^^\n");
        printf("---------------------------------------------------------------------\n");

        printf("얻은 금액 : %d \n", 2 * betting_money);
        YOU.Money += 2 * betting_money;

        COMPUTER.loss++;
        YOU.Wins++;
    }

    else if( calcscore(score_dealer, score_player) == Draw){
        printf("---------------------------------------------------------------------\n");
        printf("사용자 카드의 합 %d 딜러카드의 합 : %d\n",sum_of_score_player,sum_of_score_dealer);
        printf("무승부 입니다!\n");
        printf("---------------------------------------------------------------------\n");
        COMPUTER.draws++;
        YOU.draws++;
    }

    else if( calcscore(score_dealer, score_player) == Win){
        printf("---------------------------------------------------------------------\n");
        printf("사용자 카드의 합 %d 딜러카드의 합 : %d\n",sum_of_score_player,sum_of_score_dealer);
        printf("사용자님이 이겼습니다!\n");
        printf("---------------------------------------------------------------------\n");

        printf("얻은 금액 : %d \n", betting_money);
        YOU.Money += betting_money;

        COMPUTER.loss++;
        YOU.Wins++;
    }
    else if( calcscore(score_dealer, score_player) == lose){
        printf("---------------------------------------------------------------------\n");
        printf("사용자 카드의 합 %d 딜러카드의 합 : %d\n",sum_of_score_player,sum_of_score_dealer);
        printf("사용자님이 졌습니다!\n");
        printf("---------------------------------------------------------------------\n");

        printf("잃은 금액 : %d \n", betting_money);
        YOU.Money -= betting_money;

        YOU.loss++;
        COMPUTER.Wins++;
    }

    else if( calcscore(score_dealer, score_player) == Bust){
        printf("---------------------------------------------------------------------\n");
        printf("사용자 카드의 합 %d 딜러카드의 합 : %d\n",sum_of_score_player,sum_of_score_dealer);
        printf("Dealer's Bust!\n");
        printf("사용자님이 이겼습니다^^\n");
        printf("---------------------------------------------------------------------\n");

        printf("얻은 금액 : %d \n",  betting_money);
        YOU.Money +=  betting_money;

        COMPUTER.loss++;
        YOU.Wins++;
    }
    else if( calcscore(score_dealer, score_player) == -Bust){
        printf("---------------------------------------------------------------------\n");
        printf("사용자 카드의 합 %d 딜러카드의 합 : %d\n",sum_of_score_player,sum_of_score_dealer);
        printf("Your Bust!\n");
        printf("사용자님이 졌습니다!\n");
        printf("---------------------------------------------------------------------\n");

        printf("잃은 금액 : %d \n", betting_money);
        YOU.Money -= betting_money;

        YOU.loss++;
        COMPUTER.Wins++;
    }
    printf("---------------------------------------------------------------------\n");
    printf("★사용자 정보★\n 승리 : %d 무승부 : %d 패배 : %d 보유 금액 : %d\n",YOU.Wins, YOU.draws, YOU.loss,YOU.Money);
    printf("---------------------------------------------------------------------\n");
    printf("☆딜러 정보☆\n 승리 : %d 무승부 : %d 패배 : %d\n",COMPUTER.Wins, COMPUTER.draws, COMPUTER.loss);
    printf("---------------------------------------------------------------------\n\n");


    if(YOU.Money == 0) {
        finish_option = 'N';
    }

    else {
        printf("계속 하시겠습니까?\nY/N\n");
        FLUSH;
        while( (finish_option != 'N') && (finish_option != 'Y')) {
                scanf("%c",&finish_option);
                if((finish_option != 'N') && (finish_option != 'Y'))
                    printf("다시 입력하세요.\n");
            }
    }


    switch (finish_option){
        case 'Y':{
        printf("---------------------------------------------------------------------\n");
        printf("게임을 계속 진행합니다.\n");
        printf("---------------------------------------------------------------------\n");
        printf("\n\n\n");

        betting_money = 101;
        finish_option = 'O';
        sum_of_score_player = 0;
        sum_of_score_dealer = 0;
        first_cycle_process_player = 1;
        first_cycle_process_dealer = 1;
        check_HIT = 0;
        break;
        }

        case 'N':{
        printf("---------------------------------------------------------------------\n\n");
        printf("게임을 종료합니다.\n");
        printf("---------------------------------------------------------------------\n\n");/**<  */
        finish_option = 'N';

        free(gamedeck);
        free(copy_deck);
        free(YOU.player_cards);
        free(COMPUTER.dealer_cards);

        break;
        }

     }

  }
    return 0;
}

CARD* initDeck()
{
    CARD* deck;
    deck = (CARD*)malloc(8*Num_of_Deck);
    int i = 1;

    for(i = 0; i<Num_of_Deck; i++){     // deck.Suit 구성.
                                        // Num_of_Deck = 52
        if(i<13)                        // 처음 13개의 카드에는 D를 넣어준다.
        deck[i].Suit = D; //Diamond     // 그 다음 13개는 C, 그다음 13개는 S, 마지막 13개는 H

        else if(i<26)
        deck[i].Suit = C; //Clover

        else if(i<39)
        deck[i].Suit = S; //Spade

        else if(i<52)
        deck[i].Suit = H; //Heart
    }

    for(i = 0; i<Num_of_Deck; i++){     // deck.Number 구성.
                                        // Num_of_Deck = 52
        if( i%13 < 9)                   // 13개의 카드 중 처음 9개의 카드에는 2부터 9까지의 숫자를 넣는다.
        deck[i].Number = (i%13) + 2;    // 그 다음 4장의 카드는 J,Q,K,A를 각각 넣어준다.
                                        // 4번 반복 한다.
        else if( i%13 == 9)
        deck[i].Number = 'J'; //Jack

        else if( i%13 == 10)
        deck[i].Number = 'Q'; //Queen

        else if( i%13 == 11)
        deck[i].Number = 'K'; //King

        else if( i%13 == 12)
        deck[i].Number = 'A'; //Ace
    }
    return deck;
}

 void shuffleDeck(CARD* deck)
 {
     CARD tmp;
     srand(time(NULL));
     int i = 0;

     for(i = 0; i <Num_of_Deck; i++){

        int randnum = rand()%52;
        tmp = deck[i];
        deck[i] = deck[randnum];
        deck[randnum] = tmp;
     }

 }

CARD* getCard(CARD* deck)
{
    int i = 0;
    CARD return_card;

    if(deck != NULL){
        copy_deck = deck;
        return_card = deck[0];

        for( i = 0; i <Num_of_Deck; i++)
        {
         copy_deck[i] = copy_deck[i+1];
        }


     return ( &return_card );
    }

    else{
        return_card = copy_deck[0];

        for( i = 0; i <Num_of_Deck; i++)
        {
         copy_deck[i] = copy_deck[i+1];
        }


     return ( &return_card );
    }
}


int processPlayer(CARD* player_cards)
{
    char split = 0;
    char option = 0;
    char split_option = 'O';
    int Ace_value = 0;

    if( first_cycle_process_player == 1 ){

        if( player_cards[0].Number == 'A' || player_cards[1].Number == 'A'){
            printf("A를 1이나 11로 사용할수 있습니다. 어떤 숫자로 사용하시겠습니까?\n");
            while(Ace_value != 1 && Ace_value != 11){
                scanf("%d",&Ace_value);
                if(Ace_value != 1 && Ace_value != 11){
                    Ace_value = 5;
                    FLUSH;
                    printf("다시입력해 주세요.\n");
                }
            }

            if(player_cards[0].Number == 'A')
                player_cards[0].Number =  Ace_value;

            if(player_cards[1].Number == 'A')
                player_cards[1].Number =  Ace_value;
        }

        switch(player_cards[0].Number){
            case 'J':
                case 'Q':
                case 'K':
                player_cards[0].Number = 10;
                break;
                }
        switch(player_cards[1].Number){
                case 'J':
                case 'Q':
                case 'K':
                player_cards[1].Number = 10;
                break;
                }

        if( player_cards[0].Number ==  player_cards[1].Number ){
            printf("같은 숫자의 카드가 나왔네요 스플릿 하시겠습니까?\n");
            printf("Y/N\a\n");
            while( split != 'Y' && split != 'N' ){
                scanf("%c",&split);
                FLUSH;
                 if(split != 'Y' && split != 'N' ){
                    printf("다시 입력해주세요.\n");
                 }
            }


            if( split == 'Y'){
                    betting_money += betting_money; // 스플릿 함에따라 2배로 배팅금액 증가.

                    CARD player_cards_2; //스플릿에 사용할 새로운 사용자 카드배열.

                    player_cards_2 = *getCard(NULL);

                    printf("스플릿 되었습니다.\n");

                    printf("-------------첫번째 패로 만들어진 게임------------\n");

                    printf("새로 받은 카드\n");
                    print_card(player_cards[1]);
                    printf("원래 있던 카드\n");
                    print_card(player_cards_2);

                    if( player_cards_2.Number == 'A'){
                            printf("A를 1이나 11로 사용할수 있습니다. 어떤 숫자로 사용하시겠습니까?\n");
                        while(Ace_value != 1 && Ace_value != 11){
                                scanf("%d",&Ace_value);
                            if(Ace_value != 1 && Ace_value != 11){
                                    Ace_value = 5;
                                    FLUSH;
                                    printf("다시입력해 주세요.\n");
                                }
                        }

                        if(player_cards_2.Number == 'A')
                                player_cards_2.Number =  Ace_value;
                    }

                    switch(player_cards_2.Number){
                            case 'J':
                            case 'Q':
                            case 'K':
                            player_cards_2.Number = 10;
                            break;
                    }

                    sum_of_score_player = player_cards[1].Number + player_cards_2.Number;
                    printf("\n●사용자 카드의 합● : %d\n", sum_of_score_player);

                    printf("이 카드뭉치로 게임을 진행 하시겠습니까?\n");
                    printf("Y/N\n");

                    while(split_option != 'Y' && split_option != 'N'){
                        scanf("%c",&split_option);
                        if(split_option != 'Y' && split_option != 'N'){
                                FLUSH;
                                printf("다시 입력해 주세요.\n");
                        }
                    }




                    if(split_option == 'N'){
                        printf("두번째 카드뭉치로 게임을 진행합니다.\n");
                        player_cards[1] = *getCard(NULL);
                        if( player_cards[1].Number == 'A'){
                            printf("A를 1이나 11로 사용할수 있습니다. 어떤 숫자로 사용하시겠습니까?\n");
                            while(Ace_value != 1 && Ace_value != 11){
                                    scanf("%d",&Ace_value);
                                    if(Ace_value != 1 && Ace_value != 11){
                                        Ace_value = 5;
                                        FLUSH;
                                        printf("다시입력해 주세요.\n");
                                    }
                            }

                            if(player_cards[1].Number == 'A')
                                player_cards[1].Number =  Ace_value;
                        }

                        switch(player_cards[1].Number){
                            case 'J':
                            case 'Q':
                            case 'K':
                                player_cards[1].Number = 10;
                            break;
                        }
                        sum_of_score_player = player_cards[0].Number + player_cards[1].Number;
                    }
            }
            else if(split == 'N')
                printf("스플릿 하지않고 진행하겠습니다.\n");

        if(split_option != 'Y'){
        sum_of_score_player = player_cards[0].Number + player_cards[1].Number;
        printf("\n●사용자 카드의 합● : %d\n", sum_of_score_player);
        }
    }

}





    if( check_HIT ){
        printf("----------------------사용자가 새로 뽑은 카드------------------------\n");
        print_card(player_cards[player_card_number]);


        if( player_cards[player_card_number].Number == 'A'){
            printf("A를 1이나 11로 사용할수 있습니다. 어떤 숫자로 사용하시겠습니까?\n");
            while(Ace_value != 1 && Ace_value != 11){
                FLUSH;
                scanf("%d",&Ace_value);
                    if( Ace_value != 1 && Ace_value != 11 ){
                        Ace_value = 5;
                        printf("다시 입력해 주세요.\n");
                    }
            }
            player_cards[player_card_number].Number =  Ace_value;
        }

        switch(player_cards[player_card_number].Number){
            case 'J':
            case 'Q':
            case 'K':
               player_cards[player_card_number].Number = 10;
               break;
            }

        sum_of_score_player += player_cards[player_card_number].Number;

        printf("\n\n●사용자 카드의 합● : %d\n", sum_of_score_player);
    }


    if( sum_of_score_player == 21 && first_cycle_process_player == 1){
        return (firstBlackjack);  // 처음에 받은 카드 두장이 블랙잭일 경우.
    }
    else if( sum_of_score_player == 21 ){
        return (Blackjack); // 그 외의 Blackjack
    }
    else if( 21 < sum_of_score_player ){
        return (-Bust);   //Bust
    }

    else{
        printf("\n◆Hit : 카드 한장더 받기 [※주의사항 : 카드의 합이 21을 넘기면 패배 합니다.]\n◆Stand : 멈추고 턴 넘기기.\n");
        printf("Hit / 'H' 입력. Statnd / 'S' 입력.\n");
            while( (option != 'H') && (option != 'S') ){
                FLUSH;
                scanf("%c",&option);

                switch (option){
                    case 'H':{
                        check_HIT = 1;
                        first_cycle_process_player++;

                        player_card_number++;
                        player_cards[player_card_number] = *getCard(NULL);

                        processPlayer(player_cards);


                        if( sum_of_score_player == 21 ){
                                return (Blackjack); // Blackjack
                            }
                        else if( 21 < sum_of_score_player ){
                                return (-Bust);   //Bust
                            }

                        return (sum_of_score_player);
                        break;
                    }

                    case 'S':{
                        check_HIT = 0;
                            if( 21 < sum_of_score_player ){
                                return (-Bust);   //Bust
                            }
                            else if( sum_of_score_player == 21 ){
                                return (Blackjack); // Blackjack
                            }
                        return (sum_of_score_player);
                    }

                    default:{
                        printf("선택 사항에 없습니다.\n");
                        printf("H와 S 둘 중에서 다시 입력해주세요.\n");
                    }

            }
        }

    }
}


int processDealer(CARD* dealer_cards)
{
    int Ace_value = 0;

    if(first_cycle_process_dealer == 1){
        printf("\n\n--------------------------딜러의 턴------------------------------\n");
        printf("딜러의 패를 공개합니다.\n");
        print_card(dealer_cards[0]);
        print_card(dealer_cards[1]);

        switch(dealer_cards[0].Number){
            case 'J':
            case 'Q':
            case 'K':
                dealer_cards[0].Number = 10;
            break;
        }
        switch(dealer_cards[1].Number){
            case 'J':
            case 'Q':
            case 'K':
                dealer_cards[1].Number = 10;
            break;
        }

        if(dealer_cards[0].Number == 'A'){
                dealer_cards[0].Number =  11;
        }

        if(dealer_cards[1].Number == 'A'){
                dealer_cards[1].Number =  11;
        }

        sum_of_score_dealer = dealer_cards[0].Number + dealer_cards[1].Number;

        if(21 < sum_of_score_dealer){
            if(dealer_cards[0].Number == 'A')
                dealer_cards[0].Number = 1;
            else if(dealer_cards[1].Number == 'A')
                dealer_cards[1].Number = 1;

            sum_of_score_dealer = dealer_cards[0].Number + dealer_cards[1].Number;
        }

        printf("\n\n○딜러의 카드의 합○ : %d\n",sum_of_score_dealer);
        check_HIT = 0;
    }


    if( 21 <sum_of_score_dealer ){
        return (Bust);   //Bust
    }

    else if( 17 <= sum_of_score_dealer){   //Stand
        return (sum_of_score_dealer);
    }

    while( sum_of_score_dealer <= 16 ){
        printf("딜러의 HIT\n");
        printf("-----------------------딜러가 새로 뽑은 카드-------------------------\n");
        dealer_card_number++;
        dealer_cards[dealer_card_number] = *getCard(NULL);
        print_card( dealer_cards[dealer_card_number] );

        switch(dealer_cards[dealer_card_number].Number){
            case 'J':
            case 'Q':
            case 'K':
               dealer_cards[dealer_card_number].Number = 10;
            break;
        }

        if(dealer_cards[dealer_card_number].Number == 'A'){
            dealer_cards[dealer_card_number].Number =  11;
        }

        sum_of_score_dealer =  sum_of_score_dealer + dealer_cards[dealer_card_number].Number;

        if( (21<sum_of_score_dealer) && (dealer_cards[dealer_card_number].Number ==  11 )){
                dealer_cards[dealer_card_number].Number = 1;
                sum_of_score_dealer = sum_of_score_dealer - 10;
            }

        printf("\n\n○딜러의 카드의 합○ : %d\n",sum_of_score_dealer);
    }

    if( 21 <sum_of_score_dealer ){
        return (Bust);   //Bust
    }

    else if( 17 <= sum_of_score_dealer){   //Stand
        return (sum_of_score_dealer);
    }


}


int calcscore(int score_dealer,int score_player)
{
    if( score_player == firstBlackjack )
        return (firstBlackjack);

    else if( score_player == Blackjack )
        return (Blackjack);     // player blackjack

    else if( score_player == -Bust )                           //룰을 고려해서 순서대로 승패를 판단합니다.
        return (-Bust);     // player Bust               //사용자의 버스트, 딜러의 버스트, 별우선

    else if( score_dealer == Bust )                     //합산이 높은 쪽의 승리
        return (Bust);     // dealer Bust              //블랙잭 판

    else if( score_player == score_dealer )
        return (Draw);       // draw

    else if( (score_player < score_dealer ) )
        return (lose);      // player lose

    else if( (score_dealer < score_player )  )
        return (Win);       // player win




}

void print_card(CARD info)
{
    switch(info.Suit){
        case H:{
            printf("\n\t\t------\n\t\t|%-4c|\n\t\t|    |\n\t\t",'H');
            break;
        }
        case C:{
            printf("\n\t\t------\n\t\t|%-4c|\n\t\t|    |\n\t\t",'C');
            break;
        }
        case S:{
            printf("\n\t\t------\n\t\t|%-4c|\n\t\t|    |\n\t\t",'S');
            break;
        }
        case D:{
            printf("\n\t\t------\n\t\t|%-4c|\n\t\t|    |\n\t\t",'D');
            break;
        }
    }


    switch(info.Number){
        case 'J':{
            printf("|%4c|\n\t\t------\n", info.Number);
            break;
        }
        case 'Q':{
            printf("|%4c|\n\t\t------\n", info.Number);
            break;
        }
        case 'K':{
            printf("|%4c|\n\t\t------\n", info.Number);
            break;
        }
        case 'A':{
            printf("|%4c|\n\t\t------\n", info.Number);
            break;
        }
        default:{
            printf("|%4d|\n\t\t------\n", info.Number);
            break;
        }
    }
}

