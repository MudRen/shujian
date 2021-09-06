// modified by campsun 2003/09/23 ������ȡ1 gold��������¶ĳ���
#include <ansi.h>
inherit NPC;
int *stat =({0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0});
void pay_him(object who, int amount);
void clear_stat();
void pre_cal();
void create()
{
	set_name( "ƽ��", ({ "ping wei","wei" }) );
	set("long", "���Ƕĳ���һ���ĺ��֣������ϵĹ�������뻯��\n");
	set("attitude", "friendly");
	set("title", HIY "������" NOR);        
	set("age", 36);
        set("gender", "����" );


	set("str", 35);
        set("int", 28);
	set("con", 24);
	set("dex", 25);
	set("per", 8);
	set("lower_limit",1);
	set("too_late",0);
	set("first_dice",0);
        set("second_dice",0);
        set("third_dice",0);
	set("max_force",1400);
	set_skill("unarmed",100);
	set_skill("dodge",100);
	set("combat_exp", 50000);
	setup();


}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && visible(ob) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	add_action("do_bet", "bet");
	
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
                        say( "ƽ��Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "�����������֣������İɡ�\n");
                        break;
                case 1:
                        say( "ƽ���ӻ��˻����е����ӣ��е�����λ" + RANK_D->query_respect(ob)
                                + "��С�Ŀ������Һ��ڣ���Ŀ��Զ���������ɣ�\n");
                        break;
                case 2:
                        say( "ƽ��˵������λ" + RANK_D->query_respect(ob)
                                + "�������������� �������ҵģ�\n");
                        break;
        }



	return;

}
 
string *dice = ({
"[31m
	�� 

[37m",
"	��

	    ��
",
"	��
	  �� 
	    ��
",
"	[31m��  ��

	��  ��
[37m",
"	��  ��
	  ��
	��  ��
",
"	�� ��
	�� ��
	�� ��
"
		});
int do_bet(string arg)
{
        int bet_amt;
        int bet_type;
        object me, silver;
        string message;
	if(!arg || !sscanf(arg, "%d %d",bet_type,bet_amt))
                return notify_fail("bet <����> <����>\n");
	if(bet_type>18 || bet_type < 0)
		return notify_fail("����ֻ�ɴ��㵽ʮ��\n");
	me = this_player();
    if (me->query("age") < 18) return notify_fail("�㻹���ܲμ����ֶ�ͯ���˵Ļ��\n");
	if(me->is_busy())
		return notify_fail("���ϸ�������û��ɡ�\n");
	silver = present("silver_money", me);
	if(!silver) return notify_fail("������û�����ӡ�\n");
	if((int) silver->query_amount() < bet_amt)
	return notify_fail("������û����������ӡ�\n");	
	if((int) this_object()->query("lower_limit") > bet_amt)
	return notify_fail("����̨����С��ע��"+chinese_number((int) this_object()->query("lower_limit"))+"�����ӡ�\n");
        if((int) this_object()->query("too_late") )
        return notify_fail("�����������ˣ������ְɣ�\n");
	if((int) me->query("gamble/amount"))
	{ 
	if(bet_type != (int) me->query("gamble/type"))
	return notify_fail("�㲻����һ�����²�ͬ��ע��\n");
        silver->add_amount(-bet_amt);
        me->start_busy(1);
        if(bet_type == 0)
                message = sprintf(RED"С"NOR);
        if(bet_type == 1)
                message = sprintf(RED"��"NOR);
        if(bet_type == 2)
                message = sprintf(RED"Χ��"NOR);
        if(bet_type >=3)
                message = sprintf(RED"%s"NOR,chinese_number(bet_type));
       message_vision(sprintf("$N�ִ������ó�%s����������ѹ��%s�ϣ�\n",
                                chinese_number(bet_amt), message), me);
        bet_amt += (int) me->query("gamble/amount");
                me->set("gamble/amount",bet_amt);

	}
	else
	{
	silver->add_amount(-bet_amt);
	me->start_busy(1);
	if(bet_type == 0)	
		message = sprintf(RED"С"NOR);
	if(bet_type == 1)
		message = sprintf(RED"��"NOR);
        if(bet_type == 2)
                message = sprintf(RED"Χ��"NOR);
	if(bet_type >=3)
                message = sprintf(RED"%s"NOR,chinese_number(bet_type));
	message_vision(sprintf("$N�������ó�%s��������ѹ��%s�ϣ�\n",
				chinese_number(bet_amt), message), me);
	me->set("gamble/type",bet_type);
	me->set("gamble/amount",bet_amt);
	}
	stat[bet_type] += bet_amt;
	if( find_call_out("rolldice") == -1)
		call_out("rolldice",30);
	if( find_call_out("rolldice") >10 && find_call_out("advertise") == -1)
		call_out("advertise",random(5)+1);
return 1;
}
void advertise()
{
        switch( random(3) ) {
                case 0:
message_vision("$N����Ц��������ע����ע��һ����Ӯ��\n",this_object());
                        break;
                case 1:
message_vision("$N˵�����ٲ���ע���������ˣ�\n",this_object());
                        break;
                case 2:
message_vision("$N�����⣬�����Ŵ�ң��ӣ��ټӴ���Ķ�ע��һ��Ӯ��\n",this_object());

                        break;
        }

        if( find_call_out("rolldice") >=10)
                call_out("advertise",random(4)+5);
return;
}

void rolldice()
{
	this_object()->set("too_late",1);
	message_vision("$N�����е����¶�ע��˵�գ������е����������������\n",this_object());
	message_vision("\n������������������������ţ������ö�������������\n",this_object());
	pre_cal();
	call_out("first_dice",3);
return;
}

void first_dice()
{
	int first;
        switch( random(3) ) {
                case 0:
        message_vision("\nһ�����ӵ��˼��£�ͣ�ڣ�\n\n",this_object());
                        break;
                case 1:
        message_vision("\nһ�����ӣ����������������˼��£�������ͣ��������\n\n",this_object());
                        break;
                case 2:
        message_vision("\n���������໥һײ��һ��ֱ����ף�\n\n",this_object());

                        break;
        }

	first = (int) this_object()->query("first_dice");
	message_vision(dice[first], this_object());
	this_object()->set("first_dice",first+1);
	call_out("second_dice",4);
return;
}

void second_dice()
{
	int second;
        switch( random(3) ) {
                case 0:
       message_vision("\n��һ�����ӻ�����ͣ��������\n\n",this_object());
                        break;
                case 1:
        message_vision("\n�ڶ��������������ת��ͣ�������ط��˸���\n\n",this_object());
                        break;
                case 2:
        message_vision("\n���������໥һײ������һ������һ����\n\n",this_object());

                        break;
        }
        second= (int) this_object()->query("second_dice");
        message_vision(dice[second], this_object());
        this_object()->set("second_dice",second+1);
	call_out("third_dice",5);


return;
}
void third_dice()
{
        int third;
        switch( random(3) ) {
                case 0:
       message_vision("\n���һ�����������ﻬ�����£�����ͣ�ڣ�\n\n",this_object());
                        break;
                case 1:
        message_vision("\n�������һ�����������޵�ת����ͣ�������ڣ�\n\n",this_object());
                        break;
                case 2:
        message_vision("\n���һ������Ҳ����ͣ���ˣ�\n\n",this_object());

                        break;
        }
        third= (int) this_object()->query("third_dice");
        message_vision(dice[third], this_object());
        this_object()->set("third_dice",third+1);
        call_out("end_the_round",2);


return;
}

void end_the_round()
{
	int tot,reward,i,first, second, third;
	object *inv;
	first = (int) this_object()->query("first_dice");
        second= (int) this_object()->query("second_dice");
        third = (int) this_object()->query("third_dice");

// announce results:
message_vision(sprintf("\n$N�����е���%s��%s��%s��",
		chinese_number(first),chinese_number(second),chinese_number(third)),
		this_object());
// see who is the winner!
if( second == first && third == first)
{
message_vision("��Сͨ�ԣ���\n",this_object());
inv = all_inventory(environment(this_object()));
        for(i=0; i<sizeof(inv); i++) {
	if( userp(inv[i]) && (int) inv[i]->query("gamble/amount") )
	{
		if((int) inv[i]->query("gamble/type") == 2)
		{
		message_vision("Ӯ�ң�$N��һ����ʮ������\n",inv[i]);
		reward = (int) inv[i]->query("gamble/amount") * 37 * 100;
// also increae his betting skill
		inv[i]->improve_skill("betting", reward/100/37 * 36);
		pay_him( inv[i],reward);
		}
		inv[i]->set("gamble/amount",0);
	}
        }


}
else
{
tot = first+second+third;
message_vision(sprintf("%s�㣬",chinese_number(tot)),this_object());
if( tot>10 )
message_vision("����С��\n",this_object());
else
message_vision("��С�Դ�\n",this_object());


inv = all_inventory(environment(this_object()));
        for(i=0; i<sizeof(inv); i++) {
        if( userp(inv[i]) && (int) inv[i]->query("gamble/amount") )
        {
		if((int) inv[i]->query("gamble/type") == tot)
		{
                message_vision("Ӯ�ң�$N��һ��ˣ�\n",inv[i]);
                reward = (int) inv[i]->query("gamble/amount") * 9 * 100;
// also increae his betting skill
                inv[i]->improve_skill("betting", reward/100 /9 * 8);
                pay_him( inv[i],reward);
                inv[i]->set("gamble/amount",0);
		}
		else 
                if(((int) inv[i]->query("gamble/type") == 0 && tot <=10 ) ||
			((int) inv[i]->query("gamble/type") == 1 && tot > 10 ))
                {
                message_vision("Ӯ�ң�$N��һ��һ��\n",inv[i]);
                reward = (int) inv[i]->query("gamble/amount") * 2 * 100;
// also increae his betting skill
                inv[i]->improve_skill("betting", reward/100 / 2 * 1);
                pay_him( inv[i],reward);
                inv[i]->set("gamble/amount",0);
		}
		else
		{
// here are the losers
		reward = (int) inv[i]->query("gamble/amount");
		inv[i]->decrease_skill("betting", reward, 1);
                inv[i]->set("gamble/amount",0);
		}
        }
        }


}
this_object()->set("too_late",0);
this_object()->set("first_dice",0);
this_object()->set("second_dice",0);
this_object()->set("third_dice",0);
clear_stat();
return;
}
void pay_him(object who, int amount)

{
        object ob;

        if( amount < 1 ) amount = 1;
        if( amount/10000 ) {
                ob = new(GOLD_OB);
                ob->set_amount(amount/10000);
		ob->set("name","��Ҷ��");
                ob->move(who);
                amount %= 10000;
        }
        if( amount/100 ) {
                ob = new(SILVER_OB);
                ob->set_amount(amount/100);
                ob->move(who);
                amount %= 100;
        }
        if( amount ) {
                ob = new(COIN_OB);
                ob->set_amount(amount);
                ob->move(who);
        }
}
int accept_object(object who, object ob)
{
	int bet_type;
	string message;
	
    if( ob->value() >= 100) {
    say("ƽ���Ǻǵ�Ц����л��...\n");
	message_vision("$N��$n�����ֹ��˼��䣮��\n",this_object(),who);
	bet_type = random(19);
    if(bet_type == 0)
    	message = sprintf(RED"С"NOR);
    if(bet_type == 1)
        message = sprintf(RED"��"NOR);
    if(bet_type == 2)
        message = sprintf(RED"Χ��"NOR);
    if(bet_type >=3)
        message = sprintf(RED"%s"NOR,chinese_number(bet_type));

	if(ob->value()<10000)
		tell_object(who,"ƽ�����ĸ����㣺���ֶ�ѹ"+message+"��һ��Ӯ��\n");
	else
	{
		tell_object(who,HBBLU"ƽ�����ĸ����㣺������������¿���������̨����һ��Ҫȥ��һ��Ŷ��\n"NOR);
		who->set_temp("dxdc/enter",1);	
	}	
		message_vision("$N���ĵ�΢Ц��������\n",who);

	return 1;
                } 
    else {
		say("ƽ��˵�������Ǯ�㻹���Լ��ðɣ�\n");
        return 0;
         }
         
        return 0;
}

void clear_stat()
{
	int i;
	for(i=0;i<=18;i++)
		stat[i]=0;
}

void pre_cal()
{
this_object()->set("first_dice",0);
this_object()->set("second_dice",0);
this_object()->set("third_dice",0);
	if( !random(25)) {
// this is where we see what to come out to win for the casino!
// there never is a fair bet *grin
	int index = 12;
	int amount ;
	int i;
	int stp;
	stat[2] *= 36;
	for(i=3;i<=10;i++)
		stat[i] = 8*stat[i] + stat[0];
	for(i=11;i<=18;i++)
		stat[i] = 8*stat[i] + stat[1];
	stat[3] += stat[2];
	stat[18] += stat[2];
	amount = stat[12];

// now we have in this arry stat[] the amount of money we have to pay i
// have to pay
	for(i=11;i<=18;i++)
		if( stat[i] < amount)
			{
				amount = stat[i];
				index = i;
			}	
	stp = 2;
	for(i=10;i>=stp;i--)
		if( stat[i] < amount)
                        {
                                amount = stat[i];
                                index = i;
                        }

		if( index == 2  )
		{
		amount = random(6);
		this_object()->set("first_dice",amount);
                this_object()->set("second_dice",amount);
                this_object()->set("third_dice",amount);
		}
		else 
		if( index == 3)
		{
                amount = 0; 
                this_object()->set("first_dice",amount);
                this_object()->set("second_dice",amount);
                this_object()->set("third_dice",amount);
                }
		else
		if( index == 18 )
		{
                amount = 5;
                this_object()->set("first_dice",amount);
                this_object()->set("second_dice",amount);
                this_object()->set("third_dice",amount);
		}
		else
		{
		if( index / 3 * 3 == index ) amount = index / 3 + 1;
		else
		amount = index / 3;
		this_object()->set("first_dice",amount-1);
		index -= amount;
		amount = index / 2;
		this_object()->set("second_dice",amount-1);
		index -= amount;
		amount = index /1;
		this_object()->set("third_dice",amount-1);
		}

	}
	else
	{
this_object()->set("first_dice",random(6));
this_object()->set("second_dice",random(6));
this_object()->set("third_dice",random(6));
	}

}
