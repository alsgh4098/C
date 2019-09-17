#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FLUSH while(getchar()!='\n')

/* Blackjack 201221118 �̵���а� ����ȣ
  2015/06/03 ~~ 2015/06/14  ���� ����� */

enum { Num_of_Deck = 52, lose = -1 , Draw = 0, Win = 1, Bust = 50, Blackjack = 100 , firstBlackjack = 200};     // ���и� �Ǻ��ϱ� ���� ������ ��Ȳ�� �̸��� �ٿ����ϴ�. ���ڿ� ū �ǹ̴� �����ϴ�.
enum { H, C, S, D }; // H : HEART , C : CLOVER , S : SPADE , D : DIAMOND

typedef struct { int Suit; int Number; }CARD;
typedef struct { int Money; int Wins; int loss; int draws; CARD* player_cards; }PLAYER;
typedef struct { int Wins; int loss; int draws; CARD* dealer_cards; }DEALER;

CARD* initDeck();   // ī���� ������ �����ϴ� �Լ�.
void shuffleDeck( CARD* deck ); // ī�带 ���� �����ִ� �Լ�.
CARD* getCard( CARD* deck );    // ī�带 �� �徿 �̾� �ִ� �Լ�.
int processPlayer( CARD* player_cards ); // ������� ī�并ġ ���.
int processDealer( CARD* dealer_cards ); // ������ ī�并ġ ���.
void print_card(CARD info); // ī�� ���� ����Լ�.

CARD* copy_deck;    // getcard���� ���.  gamedeck���� ���� �޾� ������ ���� �Ű����� ���̵� ���� ���� �� �� �ֵ���.

int sum_of_score_player = 0;  // �÷��̾��� ī���� ��.
int sum_of_score_dealer = 0;  // ������ ī���� ��.
int first_cycle_process_player = 1; //���� ī����� ó�� ���� �Ǻ�.
int first_cycle_process_dealer = 1; //�÷��̾� ī����� ó�� ���� �Ǻ�.
int check_HIT = 0;  //HIT���� �Ǻ�
int dealer_card_number = 1; // ������ ���� �ִ� ī���� �� /0 ���� ��� (ó�� 2�� �����ϱ� ����.)
int player_card_number = 1; // �÷��̾ ���� �ִ� ī���� ��/ 0 ���� ��� (ó�� 2�� �����ϱ� ����.)
int betting_money = 101;    // ������ ��.

int main()
{
    DEALER COMPUTER;
    PLAYER YOU;

    COMPUTER.draws = 0; COMPUTER.Wins = 0; COMPUTER.loss = 0;
    YOU.draws = 0; YOU.Wins = 0; YOU.loss = 0;YOU.Money = 1;
    char finish_option = 'O';
    int score_dealer = 0;   // ������ ī����� ���� // �������� �ºθ� ������ ���.
    int score_player = 0;   // �÷��̾��� ī����� ���� // �������� �ºθ� ������ ���.


    printf("---------------------------------------------------------------------\n");
    printf("\t\t\tLet's play BLACKJACK!!\n");
    printf("---------------------------------------------------------------------\n");
    printf(" �ߢ����������� �ϱ⿡ ȭ���� �۽��ϴ�. ȭ���� Ű�� �ּ���.�ߢ�����\n\n");
    printf("---------------------------------------------------------------------\n");
    printf("������ ��� ���� �׼�(5�� ����� ������)�� �Է��� �ּ���.\n");
    printf("---------------------------------------------------------------------\n");

    while( (YOU.Money % 5) != 0 ){
        scanf("%d",&YOU.Money);
             printf("���ǿ� �°� �ٽ� �Է��� �ּ���.\n");
        if(YOU.Money == 0)
            YOU.Money = 51;     // 0�� �Է¹޾��� �� �ݺ����� ��� �ݺ��ϱ� ����.
        if( ( ( 0 < YOU.Money ) && (YOU.Money % 5) == 0 ) ) // �ݺ������� �ȿ��� 0�� �ƴ� ���� �Է¹޾��� �� �ݺ����� ���������� ����.
            break;
        else
            FLUSH;
    }

  while( finish_option != 'N' ){    // finish_option, �����ִ� ���� �� �������ų� N�� �Է� �޾����� ������ �����.

    printf("---------------------------------------------------------------------\n");
    printf("�ڻ���� ������\n �¸� : %d ���º� : %d �й� : %d ���� �ݾ� : %d\n",YOU.Wins,YOU.draws,YOU.loss,YOU.Money);
    printf("---------------------------------------------------------------------\n");
    printf("�ٵ��� ������\n �¸� : %d ���º� : %d �й� : %d\n",COMPUTER.Wins,COMPUTER.draws,COMPUTER.loss);
    printf("---------------------------------------------------------------------\n\n\n\n");

    YOU.player_cards = (CARD*)(malloc(8*10)); // ������� ī�� ���� 10ĭ�� �������� ����.
    COMPUTER.dealer_cards = (CARD*)(malloc(8*10));  // ��ǻ���� ī�� ���� 10ĭ�� �������� ����.

    CARD* gamedeck; // ��ü ���� ����.
    copy_deck = (CARD*)malloc(8*Num_of_Deck);   //��ü ���� �� 52ĭ�� ī�带 ������� ������ ����.

    gamedeck = initDeck();  // ��ü ���� ī���� ������ ����.

    shuffleDeck(gamedeck);  // ���� ������.

    YOU.player_cards[0] = *getCard(gamedeck);
    YOU.player_cards[1] = *getCard(NULL);
    COMPUTER.dealer_cards[0] = *getCard(NULL);
    COMPUTER.dealer_cards[1] = *getCard(NULL);

    printf("====================================================================\n");
    printf("�ٵ�����");
    printf(" ������ ������ ������ ī��\n");
    print_card( COMPUTER.dealer_cards[0] );

    printf("====================================================================\n\a");
    printf("�ڻ���ڡ�\n");
    printf(" ����ڰ� ó�� ���� ������ ī��\n");
    print_card( YOU.player_cards[0] );
    print_card( YOU.player_cards[1] );
    printf("������ �ݾ��� �Է��� �ּ���. ���������� 5�� ������� �Դϴ�.\n");

    while( betting_money % 5 != 0 ){
        scanf("%d",&betting_money );

        if( (50 < betting_money || betting_money < 0) || betting_money % 5 != 0){
            betting_money = 1;
            FLUSH;
            printf("�ٽ� �Է��� �ּ���.\n");
        }
        if( YOU.Money < betting_money ){
            betting_money = 1;
            FLUSH;
            printf("�ٽ� �Է��� �ּ���.\n");
        }
    }

    printf("\n���õ� �ݾ� : %d\n",betting_money);
    score_player = processPlayer( YOU.player_cards );
    score_dealer = processDealer( COMPUTER.dealer_cards );

    if( calcscore(score_dealer, score_player) == firstBlackjack){
        printf("---------------------------------------------------------------------\n");
        printf("����� ī���� �� %d ����ī���� �� : %d\n",sum_of_score_player,sum_of_score_dealer);
        printf("Your Blackjack!\n");
        printf("����ڴ��� �̰���ϴ�^^\n");
        printf("---------------------------------------------------------------------\n");

        printf("���� �ݾ� : %d \n", 3 * betting_money);
        YOU.Money += 3 * betting_money;

        COMPUTER.loss++;
        YOU.Wins++;
    }

    else if( calcscore(score_dealer, score_player) == Blackjack){
        printf("---------------------------------------------------------------------\n");
        printf("����� ī���� �� %d ����ī���� �� : %d\n",sum_of_score_player,sum_of_score_dealer);
        printf("Your Blackjack!\n");
        printf("����ڴ��� �̰���ϴ�^^\n");
        printf("---------------------------------------------------------------------\n");

        printf("���� �ݾ� : %d \n", 2 * betting_money);
        YOU.Money += 2 * betting_money;

        COMPUTER.loss++;
        YOU.Wins++;
    }

    else if( calcscore(score_dealer, score_player) == Draw){
        printf("---------------------------------------------------------------------\n");
        printf("����� ī���� �� %d ����ī���� �� : %d\n",sum_of_score_player,sum_of_score_dealer);
        printf("���º� �Դϴ�!\n");
        printf("---------------------------------------------------------------------\n");
        COMPUTER.draws++;
        YOU.draws++;
    }

    else if( calcscore(score_dealer, score_player) == Win){
        printf("---------------------------------------------------------------------\n");
        printf("����� ī���� �� %d ����ī���� �� : %d\n",sum_of_score_player,sum_of_score_dealer);
        printf("����ڴ��� �̰���ϴ�!\n");
        printf("---------------------------------------------------------------------\n");

        printf("���� �ݾ� : %d \n", betting_money);
        YOU.Money += betting_money;

        COMPUTER.loss++;
        YOU.Wins++;
    }
    else if( calcscore(score_dealer, score_player) == lose){
        printf("---------------------------------------------------------------------\n");
        printf("����� ī���� �� %d ����ī���� �� : %d\n",sum_of_score_player,sum_of_score_dealer);
        printf("����ڴ��� �����ϴ�!\n");
        printf("---------------------------------------------------------------------\n");

        printf("���� �ݾ� : %d \n", betting_money);
        YOU.Money -= betting_money;

        YOU.loss++;
        COMPUTER.Wins++;
    }

    else if( calcscore(score_dealer, score_player) == Bust){
        printf("---------------------------------------------------------------------\n");
        printf("����� ī���� �� %d ����ī���� �� : %d\n",sum_of_score_player,sum_of_score_dealer);
        printf("Dealer's Bust!\n");
        printf("����ڴ��� �̰���ϴ�^^\n");
        printf("---------------------------------------------------------------------\n");

        printf("���� �ݾ� : %d \n",  betting_money);
        YOU.Money +=  betting_money;

        COMPUTER.loss++;
        YOU.Wins++;
    }
    else if( calcscore(score_dealer, score_player) == -Bust){
        printf("---------------------------------------------------------------------\n");
        printf("����� ī���� �� %d ����ī���� �� : %d\n",sum_of_score_player,sum_of_score_dealer);
        printf("Your Bust!\n");
        printf("����ڴ��� �����ϴ�!\n");
        printf("---------------------------------------------------------------------\n");

        printf("���� �ݾ� : %d \n", betting_money);
        YOU.Money -= betting_money;

        YOU.loss++;
        COMPUTER.Wins++;
    }
    printf("---------------------------------------------------------------------\n");
    printf("�ڻ���� ������\n �¸� : %d ���º� : %d �й� : %d ���� �ݾ� : %d\n",YOU.Wins, YOU.draws, YOU.loss,YOU.Money);
    printf("---------------------------------------------------------------------\n");
    printf("�ٵ��� ������\n �¸� : %d ���º� : %d �й� : %d\n",COMPUTER.Wins, COMPUTER.draws, COMPUTER.loss);
    printf("---------------------------------------------------------------------\n\n");


    if(YOU.Money == 0) {
        finish_option = 'N';
    }

    else {
        printf("��� �Ͻðڽ��ϱ�?\nY/N\n");
        FLUSH;
        while( (finish_option != 'N') && (finish_option != 'Y')) {
                scanf("%c",&finish_option);
                if((finish_option != 'N') && (finish_option != 'Y'))
                    printf("�ٽ� �Է��ϼ���.\n");
            }
    }


    switch (finish_option){
        case 'Y':{
        printf("---------------------------------------------------------------------\n");
        printf("������ ��� �����մϴ�.\n");
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
        printf("������ �����մϴ�.\n");
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

    for(i = 0; i<Num_of_Deck; i++){     // deck.Suit ����.
                                        // Num_of_Deck = 52
        if(i<13)                        // ó�� 13���� ī�忡�� D�� �־��ش�.
        deck[i].Suit = D; //Diamond     // �� ���� 13���� C, �״��� 13���� S, ������ 13���� H

        else if(i<26)
        deck[i].Suit = C; //Clover

        else if(i<39)
        deck[i].Suit = S; //Spade

        else if(i<52)
        deck[i].Suit = H; //Heart
    }

    for(i = 0; i<Num_of_Deck; i++){     // deck.Number ����.
                                        // Num_of_Deck = 52
        if( i%13 < 9)                   // 13���� ī�� �� ó�� 9���� ī�忡�� 2���� 9������ ���ڸ� �ִ´�.
        deck[i].Number = (i%13) + 2;    // �� ���� 4���� ī��� J,Q,K,A�� ���� �־��ش�.
                                        // 4�� �ݺ� �Ѵ�.
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
            printf("A�� 1�̳� 11�� ����Ҽ� �ֽ��ϴ�. � ���ڷ� ����Ͻðڽ��ϱ�?\n");
            while(Ace_value != 1 && Ace_value != 11){
                scanf("%d",&Ace_value);
                if(Ace_value != 1 && Ace_value != 11){
                    Ace_value = 5;
                    FLUSH;
                    printf("�ٽ��Է��� �ּ���.\n");
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
            printf("���� ������ ī�尡 ���Գ׿� ���ø� �Ͻðڽ��ϱ�?\n");
            printf("Y/N\a\n");
            while( split != 'Y' && split != 'N' ){
                scanf("%c",&split);
                FLUSH;
                 if(split != 'Y' && split != 'N' ){
                    printf("�ٽ� �Է����ּ���.\n");
                 }
            }


            if( split == 'Y'){
                    betting_money += betting_money; // ���ø� �Կ����� 2��� ���ñݾ� ����.

                    CARD player_cards_2; //���ø��� ����� ���ο� ����� ī��迭.

                    player_cards_2 = *getCard(NULL);

                    printf("���ø� �Ǿ����ϴ�.\n");

                    printf("-------------ù��° �з� ������� ����------------\n");

                    printf("���� ���� ī��\n");
                    print_card(player_cards[1]);
                    printf("���� �ִ� ī��\n");
                    print_card(player_cards_2);

                    if( player_cards_2.Number == 'A'){
                            printf("A�� 1�̳� 11�� ����Ҽ� �ֽ��ϴ�. � ���ڷ� ����Ͻðڽ��ϱ�?\n");
                        while(Ace_value != 1 && Ace_value != 11){
                                scanf("%d",&Ace_value);
                            if(Ace_value != 1 && Ace_value != 11){
                                    Ace_value = 5;
                                    FLUSH;
                                    printf("�ٽ��Է��� �ּ���.\n");
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
                    printf("\n�ܻ���� ī���� �ա� : %d\n", sum_of_score_player);

                    printf("�� ī�并ġ�� ������ ���� �Ͻðڽ��ϱ�?\n");
                    printf("Y/N\n");

                    while(split_option != 'Y' && split_option != 'N'){
                        scanf("%c",&split_option);
                        if(split_option != 'Y' && split_option != 'N'){
                                FLUSH;
                                printf("�ٽ� �Է��� �ּ���.\n");
                        }
                    }




                    if(split_option == 'N'){
                        printf("�ι�° ī�并ġ�� ������ �����մϴ�.\n");
                        player_cards[1] = *getCard(NULL);
                        if( player_cards[1].Number == 'A'){
                            printf("A�� 1�̳� 11�� ����Ҽ� �ֽ��ϴ�. � ���ڷ� ����Ͻðڽ��ϱ�?\n");
                            while(Ace_value != 1 && Ace_value != 11){
                                    scanf("%d",&Ace_value);
                                    if(Ace_value != 1 && Ace_value != 11){
                                        Ace_value = 5;
                                        FLUSH;
                                        printf("�ٽ��Է��� �ּ���.\n");
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
                printf("���ø� �����ʰ� �����ϰڽ��ϴ�.\n");

        if(split_option != 'Y'){
        sum_of_score_player = player_cards[0].Number + player_cards[1].Number;
        printf("\n�ܻ���� ī���� �ա� : %d\n", sum_of_score_player);
        }
    }

}





    if( check_HIT ){
        printf("----------------------����ڰ� ���� ���� ī��------------------------\n");
        print_card(player_cards[player_card_number]);


        if( player_cards[player_card_number].Number == 'A'){
            printf("A�� 1�̳� 11�� ����Ҽ� �ֽ��ϴ�. � ���ڷ� ����Ͻðڽ��ϱ�?\n");
            while(Ace_value != 1 && Ace_value != 11){
                FLUSH;
                scanf("%d",&Ace_value);
                    if( Ace_value != 1 && Ace_value != 11 ){
                        Ace_value = 5;
                        printf("�ٽ� �Է��� �ּ���.\n");
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

        printf("\n\n�ܻ���� ī���� �ա� : %d\n", sum_of_score_player);
    }


    if( sum_of_score_player == 21 && first_cycle_process_player == 1){
        return (firstBlackjack);  // ó���� ���� ī�� ������ ������ ���.
    }
    else if( sum_of_score_player == 21 ){
        return (Blackjack); // �� ���� Blackjack
    }
    else if( 21 < sum_of_score_player ){
        return (-Bust);   //Bust
    }

    else{
        printf("\n��Hit : ī�� ����� �ޱ� [�����ǻ��� : ī���� ���� 21�� �ѱ�� �й� �մϴ�.]\n��Stand : ���߰� �� �ѱ��.\n");
        printf("Hit / 'H' �Է�. Statnd / 'S' �Է�.\n");
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
                        printf("���� ���׿� �����ϴ�.\n");
                        printf("H�� S �� �߿��� �ٽ� �Է����ּ���.\n");
                    }

            }
        }

    }
}


int processDealer(CARD* dealer_cards)
{
    int Ace_value = 0;

    if(first_cycle_process_dealer == 1){
        printf("\n\n--------------------------������ ��------------------------------\n");
        printf("������ �и� �����մϴ�.\n");
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

        printf("\n\n�۵����� ī���� �ա� : %d\n",sum_of_score_dealer);
        check_HIT = 0;
    }


    if( 21 <sum_of_score_dealer ){
        return (Bust);   //Bust
    }

    else if( 17 <= sum_of_score_dealer){   //Stand
        return (sum_of_score_dealer);
    }

    while( sum_of_score_dealer <= 16 ){
        printf("������ HIT\n");
        printf("-----------------------������ ���� ���� ī��-------------------------\n");
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

        printf("\n\n�۵����� ī���� �ա� : %d\n",sum_of_score_dealer);
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

    else if( score_player == -Bust )                           //���� ����ؼ� ������� ���и� �Ǵ��մϴ�.
        return (-Bust);     // player Bust               //������� ����Ʈ, ������ ����Ʈ, ���켱

    else if( score_dealer == Bust )                     //�ջ��� ���� ���� �¸�
        return (Bust);     // dealer Bust              //���� ��

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

