// Room: dixiashi.c
//created by campsun 2003/09/22
#include <ansi.h>

inherit ROOM;
int create_fight();
int checkSameIp(object);
string *str_menpai = ({ "wd","hs",
			"ss","gm",
			"gb","tz",
			"dls","mr",
			"sld","xx",
			"em","mj",
			"thd","tls",
			"sl","kl"
			});	
string *str_skill_other = ({"taoism",                                           //�䵱����ѧ�ķ�
                            "begging",                                          //ؤ��л�����
                            "bangjue",                                          //ؤ��򹷰��ھ�
                            "stealing",                                         //ؤ����ֿտ�
                            "checking",                                         //ؤ�
                            "zhenqijue",                                        //��ɽ��������
                            "tiezhang-xinfa",                                   //���ƣ������ķ�
                            "huanxi-chan",                                      //�����£���ϲ��
                            "shenlong-yaoli",                                   //������������ҩ��
                            "dacheng-fofa",                                     //���ң���˷�
                            "qimen-bagua",                                      //�һ��������Ű���
                            "buddhism",                                         //�����£����֣������ķ�
                            "art",                                              //���أ������黭
                            "daode-jing",                                       //���������¾�
                            "poison",						//��������
                            "medicine",						//��������
                            "wuxing-zhen",					//�����󷨣�������
                            "zhenwu-qijiezhen",					//�䵱��
                            "dagou-zhen",					//ؤ�����
                            "linji-jianzhen",					//��ü����
                            "shenghuo-fumozhen",				//����ʥ���ħ��
                            "fumoquan-zhen",					//���ַ�ħȦ��
                            "shenlong-wudizhen",				//�����޵���
                            "qimen-baguazhen",					//���Ű�����
                                                        });															//��������������б�

string *str_chuchang_desc =({
		HIC"ͻȻ֮�䣬û������ô�ܣ���Ҿͷ���$N�Ѿ�վ������̨һ�ǡ�\n"NOR ,
		HIY"ֻ��$N��ƽ�ز��Ծ��ʹ��һ�����ӷ���������̨�ϣ��ǵĹ�������������\n"NOR ,
		HIM"$N����̨�£�������̨�Ͽ��˿���˫�ŵ�أ����������̨������һ�����������ù��򣡺ÿ��������\n"NOR ,
		HIR"ֻ��$N��������һƳ����һԾ��ƽƽ���ȵ�վ����̨�ϣ��ǵĹ�������������\n"NOR ,
		HIW"ֻ��$N����Ⱥ�Ｗ��̨�£�����һ������˫�ְ�ס̨�壬��һ��������ǫ̃̄������һָ����߾������������������\n"NOR ,
		HIB"ֻ��$Nৡ�����˦��Ӣ�۴�멣��������������ᡱһ��������̨�����������ë������̩ɽ��\n"NOR ,
		});
object red_fighter;
object black_fighter;
object laoban;
object winner;
						
string *strIpAddress;

void create()
{

	set("short", "���º�ȭ��");
	set("long", @LONG
�������ݳ��ڵ�һ�ҵ��¶ķ��������˶�֪����������˲������������ƽʱ
�б��䣬���Ƕ��������Ը���Ӯ���������ܻ�ô����Ľ�Ǯ��������򶪵�������
�����и����ӣ�paizi��,˵���˶Ĳ��Ĺ���
LONG
	);
	
	set("exits", ([
	         "up" : __DIR__"dating1",
	]));
	set("coor/x",80);
	set("coor/y",-20);
	set("coor/z",-10);
    	set("no_sleep",1);
    	set("state","");																	//�ж��Ƿ��Ѿ���ʼ

	set("yingyu",0);
    	set("winner","none");

	set("item_desc", ([
                "paizi": @TEXT
���¶ĳ��ķ�˵����

һ��yazhu <ĳ��> <����>

ĳ������red(�췽) black(�ڷ�) both(ƽ��) ���� none(ƽ��)

���������Իƽ�Ϊ��λ������1���ƽ����100����Ŀǰ������1:1.3 �� 1:20
		ƽ�ֵ������� 1:1.5
		
���ӣ�
yazhu red 50
����ʮ���ƽ��ں췽��

����dadu <ĳ��> <����> with <ĳ��>

ĳ������red(�췽) ���� black(�ڷ�)
ĳ�ˣ�  ͬһ������κ�һ���������
���������Իƽ�Ϊ��λ������50���ƽ����500����Ŀǰ������1:1
���ӣ�
dadu red 50 with test
�� test �� red Ӯ����עΪ 50 gold��test ͬ���˫���ĶĲ���Ч��

������������
��ҿ��� ask huang fuba about ���� ѯ�ʱ������
	 ask huang fuba about �Ľ� ѯ��Ѻע����͵�ǰ�����������ǰ������Ҫ��˫����Ѻע�й�
	 ask huang fuba about �һ� ������Ѱ������ϵ����Ӷһ��ɻƽ�
	 list		      ���Բ鿴�Ƹ��Գ��۵�ʳ�����ˮ
	 					
	 				   ����BUG,��SOS˵��
	 				  �齣������Ϸ����С��

TEXT
        ]) );
        

	 
     setup();      
     laoban=new("/d/city/npc/laoban.c");
     laoban->move(this_object());
     laoban->set("startroom","/d/city/dixiashi");     
     call_out("wait_fight",10);
}


void init()
{
	object me;
	me = this_player();
	add_action("do_bet","yazhu");
	add_action("do_bound","bound");
	add_action("do_dadu","dadu");															//��ģ����֮�����Ӯ
	if (userp(this_player()) && !wizardp(this_player()))
	{
    	add_action("do_action", ({"dazuo", "tuna", "lian", "learn", "du", "steal", "hit",
                             "kill", "fight", "study", "practice",
                             "emote","perform","ansuan","guard","throw","juedou","bark","steal","beg","sleep"}));
    	add_action("do_yun", ({"exert","yun","fanchang"}));									//add fanchang by campsun 2003.10.18 
                             
	}
this_player()->delete_temp("dxdc");

	if ((int)me->query_condition("killer"))										//��ֹɱ�˷��������ͨ��
	{
		write(CYN"��Ѿ�ǧ���������˶ĳ���ֻ����������Ϣһ�ᡣ\n");
		write(CYN"ͻȻ֮�䣬һ��˶�����Ӱ��������������ߣ��������İ�ʮһ�ơ�\n");
		write(CYN"���ϰ�ȵ�����ɱ������������û��ô���ף���\n");
		write(CYN"�����������ת���������׳������⡣\n");
		write(CYN"��о�����֮�󣬵������ƺ�����Щʲô��\n"NOR);
		me->move("/d/city/dating1");
		me->add("max_neili",-random(10));														//��Ϊ������bug���룬���Ը���СС�ͷ�
	}
	
	if (userp(me) && !wizardp(me)){
		if(checkSameIp(me))																			//Ϊ�˷�ֹ���gold������ߣ�ͬip��ֹһ���档
		{
	    	message_vision(HIB"\nĿǰ�ĳ�̫ӵ���ˣ�$N�����˳�ȥ��\n"NOR, me);	
	    	me->move("/d/city/dating1");			
		}
		if (!sizeof(strIpAddress)) strIpAddress=({});

		strIpAddress = strIpAddress + ({query_ip_number(me)});
	}
}

void reset()
{
return;																							//��ֹϵͳ���������ֹ�ж����ڽ��еı���
}
int do_yun()
{
	this_player()->start_busy(2);
	write("\n��մ��˸���Ƿ���;��������ڶ����㿴����ֻ�����ϰ������˻�ȥ��\n\n");
	return 1;
}
int do_action(string arg)
{
	this_player()->start_busy(2);
   	write("\n����Ҫ����������ͻȻ�������˽���һ�ģ��úÿ����䣬���Ҷ���\n\n");//��ֹ��Ҷԣ��㶯�ֽ�
   	return 1;
}
int wait_fight()
{
	object huoyan;
	string str_temp="";

	int base_exp=(random(20)+1)*1000000;														//��������������������
	int base_jiali=random(11);																	//�������������
	remove_call_out("wait_fight");

	if(objectp(red_fighter)) destruct(red_fighter);													//����췽�ͺڷ�
	if(objectp(black_fighter)) destruct(black_fighter);
	black_fighter=new("/d/city/npc/wushi");
	red_fighter=new("/d/city/npc/wushi");
	str_menpai=str_menpai-({"9y","kl","hmg","pxj","jsj"});									//�����ȥ��hmg��9y���������ӣ�������ʮ��
	if(!random(10)) str_menpai=str_menpai+({"9y"});											//�У��������ĸ��ʰѣ���������������С�ʵ�ʸ���ĿǰΪ����������
    if(!random(15)) str_menpai=str_menpai+({"hmg"});
    if(!random(8)) str_menpai=str_menpai+({"pxj"});
    if(!random(6)) str_menpai=str_menpai+({"jsj"});
    if(!random(3)) str_menpai=str_menpai+({"kl"});											//����ʵ����̫���ˣ����ٳ����صĸ���
    	set("red_party",str_menpai[random(sizeof(str_menpai))]);
    	set("black_party",str_menpai[random(sizeof(str_menpai))]);
    	if((query("red_party")=="xx" || query("black_party")=="xx") && !objectp(huoyan))
    	{
    	huoyan=new("/d/xingxiu/obj/huoyan");
    	huoyan->move(this_object());															//��������޵��Ӳ���ս����������һ������
	}	
    set("use_weapon",random(3));																//��������Ƿ�ʹ������
   	set("base_exp",base_exp);
    set("base_jiali",base_jiali);
    set("level",random(3));
   	red_fighter->set("tag","red");																//�趨�췽ѡ��
	red_fighter->move(this_object());
	black_fighter->set("tag","black");															//�趨�ڷ�ѡ��		
	black_fighter->move(this_object());
	message_vision("\n"+str_chuchang_desc[random(sizeof(str_chuchang_desc))],black_fighter);
	message_vision("\n"+str_chuchang_desc[random(sizeof(str_chuchang_desc))],red_fighter);

	if(!objectp(laoban))
		return notify_fail("���¶ĳ��ϰ�����ȥ�ˣ����ȥ��wiz���������������˲����ٱ�����\n");
	
	str_temp=HIM"\n$N˵����"+HIB"����Ĳ�������ʼ����ӭ���ӻԾ���룡\n"NOR;
	str_temp+=HIM"\n$N˵����"+HIG"��α����˫���ֱ��ǣ�\n"NOR;
	str_temp+=RED"\n              �췽��"NOR+"������"HIR+red_fighter->query("family/family_name")+NOR"��"HIW+red_fighter->query("name")+NOR"";
	str_temp+=BLU"                �ڷ���"NOR+"������"HIR+black_fighter->query("family/family_name")+NOR"��"HIW+black_fighter->query("name")+NOR"\n";
	str_temp+="\n                    ������"HIY+red_fighter->query("good_skills")+NOR"";
	str_temp+="                          ������"HIY+black_fighter->query("good_skills")+NOR"\n";   
	str_temp+=HIM"\n$N˵����"+HIB"��ֱ���������£�\n\n"NOR;
	str_temp+="           ";
	if(!query("use_weapon")) str_temp+="һ��"+HIY"���ָ� "NOR;
	else str_temp+="һ��"+HIY"������ "NOR;
	switch(query("base_jiali"))
	{
		case 0:
			str_temp+="������"+HIY"˫��"+HIC"��ʹ���������䡡"NOR;
		break;
		case 10:
			str_temp+="������"+HIY"˫��ʹ��"+HIC"ȫ�����䡡"NOR;
		break;
		default:
			str_temp+="������"+HIY"˫��ʹ��"HIC+chinese_number(query("base_jiali"))+"��"NOR+HIY"�������䡡"NOR;
	}
	str_temp+="������"+HIY"ʮ������ɱ���Է��Ļ�ʤ\n\n"NOR;
	str_temp+=HIM"$N˵����"+HIC"������ӱ�����Ҫ��ʼ�ˣ����ڴ�ҿ���ѹ�Լ�ϲ����ѡ���ˣ�\n\n"NOR;
	
	message_vision(str_temp,laoban);
	
	laoban->set("red_f_skill",red_fighter->query("good_skills"));
	laoban->set("black_f_skill",black_fighter->query("good_skills"));
	

	set("state","wait");																							//���Ի�״̬
	set("winner","none");																								//���Ի��ھ�
	set("red_money",0);																								//ѹ�ں췽���ܽ��
	set("black_money",0);																							//ѹ�ںڷ����ܽ��
	set("none_money",0);
	set("red_betrate",130);																							//�췽��ڷ������ʣ�Ŀǰ��Ϊ����������
	set("black_betrate",130);
	set("none_betrate",150);
	set("num",4);
	call_out("start_jishu",90);
	
return 1;
}
int start_jishu()
{
	remove_call_out("start_jishu");
	if(query("num"))
	{
		switch(query("num"))
		{
		case 4:
			message_vision(HIC"\n                                     ���伴����ʼ��\n"NOR,red_fighter);	
			add("num",-1);
		break;
		case 3:
			message_vision(HIY"\n               һλ����ɫ���۵�С�����������̨������һȦ������д�ţ���\n"NOR,red_fighter);	
			add("num",-1);				
		break;
		case 2:
			message_vision(HIG"\n               һλ����ɫ���۵�С�����������̨������һȦ������д�ţ���\n"NOR,red_fighter);	
			add("num",-1);				
		break;
		case 1:
			message_vision(HIW"\n               һλ����ɫ���۵�С�����������̨������һȦ������д�ţ�һ\n"NOR,red_fighter);	
			add("num",-1);				
		break;
		}
		call_out("start_jishu",1);
	}
	else

	call_out("start_fight",1);
}
int start_fight()
{

	set("state","fighting");
	remove_call_out("start_fight");
	if (!objectp(red_fighter))
	{
		message_vision("�췽ѡ�������Ӳ��ܳ�ϯ�������ⳡ����ȡ���ˡ�\n",laoban);
		call_out("wait_fight",10);
		return 0;
	}
	if (!objectp(black_fighter))
	{
		message_vision("�ڷ�ѡ�ָղ�Ť���˽ţ����ܲμӱ����ˡ��ⳡ����ȡ���ˡ�\n",laoban);					//һ�㲻�ᷢ�����������
		call_out("wait_fight",10);
		return 0;
	}
	message_vision(HIW"\n                                     ������ʼ��\n"NOR,red_fighter);	
		
	message_vision(HIR"������$N��ɱ��$n��\n"NOR,red_fighter,black_fighter);
	message_vision(HIR"������$N��ɱ��$n��\n"NOR,black_fighter,red_fighter);
	

	black_fighter->kill_ob(red_fighter);
	red_fighter->kill_ob(black_fighter);
	
	call_out("get_bound",300);																						//��ֹ����Ī������ֹͣ���ٽ���
return 1;
}
void get_bound()
{
	remove_call_out("get_bound");
	
	call_out("do_bound",random(3)+3);																				//��ֹ����һ��ѡ�ֻ��ȥ��֮ǰ�ͷ�������
}
int do_bound()
{
	string str_temp="";
	object *ob;
	object huoyan;
	object room;
	object gold_amount;
	object silver_amount;
	mapping skills;
	string* sname;
	int i,j,win_money_gold,win_money_silver,skills_i;
//	int my_dadu_gold,op_dadu_gold;
	int my_dadu_gold;
	float win_rate;
	
	remove_call_out("do_bound");
	set("state","bound");
	call_out("wait",random(3)+3);
	room=this_object();
	ob = all_inventory(room);
	switch(room->query("winner"))
	{
	case "none":
		if(objectp(red_fighter) && objectp(black_fighter))
		{
			red_fighter->remove_enemy(black_fighter);
	       	black_fighter->remove_killer(red_fighter);
		}
		message_vision(HIC"������ô�õ�ʱ�䣬$N��$n��δ��ʤ������˾���˫����ͬΪ�ھ���\n"NOR,red_fighter,black_fighter);		//����ڣ���������δ����ʤ���������
	break;
	case "red":
		if(objectp(red_fighter))
			winner=red_fighter;
	break;
	case "black":
		if(objectp(black_fighter))
			winner=black_fighter;
	break;
	
	}//end switch
	if (objectp(winner)){
	str_temp=sprintf("\n���г���̨������$N����˵�������ֵĹھ���%s��$n��\n"NOR,winner->query("family/family_name"));
	message_vision(HIY+str_temp,winner,winner);
	if(random(2))
		message_vision(CYN"$N�˷ܵ�����ڻ������⣡\n"NOR,winner);
	else
		message_vision(CYN"$N�˷ܵĶ���ҡ��β�ͣ�\n"NOR,winner);
	
	}
	win_rate=room->query(room->query("winner")+"_betrate");																		//��û�ʤ��������

	for(i=0;i<sizeof(ob);i++)
    	{
    		if( !userp(ob[i]) ) continue;
    	if (!living(ob[i])) 
    	{
    		message_vision(HIB"�Ƹ���������ü������ô�赹�����Ǯ�������£��˸����ӵ�����ȥ����\n"NOR,ob[i]);
    		
	    	message_vision(HIB"����������������д󺺣���$N���ϵ�Ǯ�������ˡ�\n"NOR, ob[i]);	
	    	
	    	gold_amount = present("gold_money", ob[i]);
	    	
	    	if (objectp(gold_amount))
	    		destruct(gold_amount);
	    	
	    	message_vision(HIB"����������������д󺺣��ѻ赹��$N���˳�ȥ��\n"NOR, ob[i]);
	    	log_file("nosave/duchangebug",
            	sprintf("%s(%s)�ڵ��º�ȭ�ε��������漰����bugĲ����\n",ob[i]->name(),ob[i]->query("id")));
	    	
	    	ob[i]->move("/d/city/dating1");
    		continue;
    	}
    	
    	//if (ob[i]->query_temp("dxdc/dadu/state") == "wait") ob[i]->delete_temp("dxdc/dadu"); //����ȴ��ߵı��
    	if(ob[i]->query_temp("dxdc/dadu/state")=="dadu")
    	{
    		my_dadu_gold=ob[i]->query_temp("dxdc/dadu/bet");
    	//	op_dadu_gold=ob[i]->query_temp("dxdc/dadu/opbet");												//��Ϊ���˫��ѹע���Ϊһ���ģ����Բ���op_dadu_gold,���ҷ����������������bug
    		if(room->query("winner")=="none")
    		{
    			gold_amount = present("gold_money", ob[i]);
    			if (objectp(gold_amount))
    			{
   					gold_amount->add_amount(my_dadu_gold);
   				}
   				else
   				{
   					if(my_dadu_gold)
   					{
   					gold_amount=new("/clone/money/gold");
 					gold_amount->set_amount(my_dadu_gold);
   					gold_amount->move(ob[i]);
   					}
   				}  
				message_vision(sprintf("��˽�µĴ���У�����˫��ս����ƽ�֣�����$N�û���%s����֤��\n",chinese_number(my_dadu_gold)), ob[i]);		
    		}
    		else
    		if(ob[i]->query_temp("dxdc/dadu/side")==room->query("winner"))
    		{
    			gold_amount = present("gold_money", ob[i]);
    			if (objectp(gold_amount))
    			{
   					gold_amount->add_amount(my_dadu_gold*2);
   				}
   				else
   				{
   					if(my_dadu_gold*2)
   					{
   					gold_amount=new("/clone/money/gold");
 				//	gold_amount->set_amount(my_dadu_gold+op_dadu_gold);
 					gold_amount->set_amount(my_dadu_gold*2);
   					gold_amount->move(ob[i]);
   					}
   				}    		
			//	message_vision(sprintf("��˽�µĴ���У�$N����ʶӢ�ۣ��û����Լ��ı�֤��%s���ƽ𣬲���Ӯ����%s���ƽ�\n",chinese_number(my_dadu_gold),chinese_number(op_dadu_gold)), ob[i]);	
				message_vision(sprintf("��˽�µĴ���У�$N����ʶӢ�ۣ��û����Լ��ı�֤��%s���ƽ𣬲���Ӯ����%s���ƽ�\n",chinese_number(my_dadu_gold),chinese_number(my_dadu_gold)), ob[i]);	
				//���佱��
				if (random(ob[i]->query_kar()) > 22  && my_dadu_gold >= 50){
				skills=ob[i]->query_skills();
				if (mapp(skills)) sname  = keys(skills);
				sname = sname - str_skill_other;
				
				skills_i=random(sizeof(sname));
				ob[i]->improve_skill(sname[skills_i], my_dadu_gold/10 + random(20));
				tell_object(ob[i], YEL "ͨ���Ժ��˫���ı����Ħ����ֻ����ǰ���ڵ�������ʻ�Ȼ���ʣ���"+to_chinese(sname[skills_i])+"�����µĸ���\n"NOR
				);
				}	
    		}
    		else
    		{
				message_vision(sprintf("��˽�µĴ���У�$N�����%s���ƽ�\n",chinese_number(my_dadu_gold)), ob[i]);		
    		}
   		ob[i]->delete_temp("dxdc/dadu");
    		
    	}
    	if(ob[i]->query_temp("dxdc/bet"))
    	{
    	if(ob[i]->query_temp("dxdc/side")==room->query("winner"))
    	{
    		win_money_gold=ob[i]->query_temp("dxdc/bet")*win_rate/100;
    		win_money_silver=to_int(ob[i]->query_temp("dxdc/bet")*win_rate*100) /100 % 100 ;																
    		
    		gold_amount = present("gold_money", ob[i]);
    		if (objectp(gold_amount))
    		{
   				gold_amount->add_amount(win_money_gold);
   			}
   				else
   			{
   				if(win_money_gold)
   				{
   				gold_amount=new("/clone/money/gold");
 				gold_amount->set_amount(win_money_gold);
   				gold_amount->move(ob[i]);
   				}
   			}
    		silver_amount = present("silver_money", ob[i]);
    		if (objectp(silver_amount))
    		{
   				silver_amount->add_amount(win_money_silver);
   			}
   				else
   			{
   				if(win_money_silver)
   				{
   				silver_amount=new("/clone/money/silver");
   				silver_amount->set_amount(win_money_silver);
   				if (win_money_silver)
   					silver_amount->move(ob[i]);
   				}
   			}
   			if (!win_money_silver)
   			{
			message_vision(sprintf(CYN+"$N����ʶӢ�ۣ��Ƹ��Ը���$N�����������ڵ�%s���ƽ�\n"+NOR,chinese_number(win_money_gold)), ob[i]);	
			//���佱��
				if (random(ob[i]->query_kar()) > 22  && ob[i]->query_temp("dxdc/bet") >= 50){
				skills=ob[i]->query_skills();
				if (mapp(skills)) sname  = keys(skills);
				sname = sname - str_skill_other;
				
				skills_i=random(sizeof(sname));
				ob[i]->improve_skill(sname[skills_i], ob[i]->query_temp("dxdc/bet")/5 + random(20));
				tell_object(ob[i], YEL "ͨ���Ժ��˫���ı����Ħ����ֻ����ǰ���ڵ�������ʻ�Ȼ���ʣ���"+to_chinese(sname[skills_i])+"�����µĸ���\n"NOR
				);
				}	
			add("yingyu",-win_money_gold*100);
			}	
			else
			{
			message_vision(sprintf(CYN+"$N����ʶӢ�ۣ��Ƹ��Ը���$N�����������ڵ�%s���ƽ�%s�����ӡ�\n"+NOR,chinese_number(win_money_gold),chinese_number(win_money_silver)), ob[i]);		
			//���佱��
				if (random(ob[i]->query_kar()) > 22  && ob[i]->query_temp("dxdc/bet") >= 50){
				skills=ob[i]->query_skills();
				if (mapp(skills)) sname  = keys(skills);
				sname = sname - str_skill_other;
				
				skills_i=random(sizeof(sname));
				ob[i]->improve_skill(sname[skills_i], 10 + random(20));
				tell_object(ob[i], YEL "ͨ���Ժ��˫���ı����Ħ����ֻ����ǰ���ڵ�������ʻ�Ȼ���ʣ���"+to_chinese(sname[skills_i])+"�����µĸ���\n"NOR
				);
				}
			add("yingyu",-win_money_silver);
			add("yingyu",-win_money_gold*100);
			}
			
    	}
    	else{
    		if(query("winner")=="none")
    		message_vision(sprintf("���ϧ,˫�������ƽ�֣�����$N����%s���ƽ�\n",chinese_number(ob[i]->query_temp("dxdc/bet"))),ob[i]);
    		else
    		if(ob[i]->query_temp("dxdc/side")=="none")
				message_vision(sprintf("���ϧ��$Nѹ����ƽ�֣������Ǿ�����ʤ��������$N����%s���ƽ�\n",chinese_number(ob[i]->query_temp("dxdc/bet"))), ob[i]);		
    			else
				message_vision(sprintf("���ϧ��$Nѹ��һ���Ѿ����ˣ�����$N����%s���ƽ�\n",chinese_number(ob[i]->query_temp("dxdc/bet"))), ob[i]);		
	    }
   	
	}
	ob[i]->delete_temp("dxdc"); //����������������˵ı��
	}
	
	if (objectp(winner))																						//��¼�������
	{
	log_file("skills/dxdc",sprintf("���±����¼��%s %s vs %s %s��exp��%dM ˫��������%d����ʤ���ǣ�%s %s\n",
		 	room->query("red_party"),
		 	laoban->query("red_f_skill"),
		 	room->query("black_party"),
		 	laoban->query("black_f_skill"),
		 	room->query("base_exp")/1000000,
		 	room->query("base_jiali")*20,
			winner->query("family/family_name"),
			winner->query("good_skills")
			));
	}
	else
	{
	log_file("skills/dxdc",sprintf("���±����¼��%s %s vs %s %s��exp��%dM ˫��������%d��˫����ƽ��\n",
		 	room->query("red_party"),
		 	laoban->query("red_f_skill"),
		 	room->query("black_party"),
		 	laoban->query("black_f_skill"),
		 	room->query("base_exp")/1000000,
		 	room->query("base_jiali")*20
		 	));						
	 }
	 	ob = all_inventory(this_object());
	for(i=0;i<sizeof(ob);i++)																	//��������ϵĲ���صĶ���
	{
		if(userp(ob[i]) || ob[i]==red_fighter || ob[i]==black_fighter || ob[i]==huoyan || ob[i]==laoban)
			continue;
		else
		{
			switch(ob[i]->query("id"))
				{
				case "corpse":
					message_vision("\n��̨������������׳������$N������ȥ��\n", ob[i]);		
				break;
				default:
					message_vision(CYN"\n����һ����$N"+CYN+"�����ˡ�\n"NOR, ob[i]);		
				}
			destruct(ob[i]);	
		}
	}
	if(objectp(winner))																				//�����һ�ιھ�
		{
			message_vision(CYN"\n$N�ڹ��ڵĴ�ӵ���뿪�˱������ء�\n"NOR, winner);
			destruct(winner);
		}
	if(objectp(red_fighter))																				
		{
			message_vision(CYN"\n$N�ڹ��ڵĴ�ӵ���뿪�˱������ء�\n"NOR, red_fighter);
			destruct(red_fighter);
		}
	if(objectp(black_fighter))																				
		{
			message_vision(CYN"\n$N�ڹ��ڵĴ�ӵ���뿪�˱������ء�\n"NOR, black_fighter);
			destruct(black_fighter);
		}				
	
		ob = all_inventory(room);	
		strIpAddress = ({});
		for(i=0;i<sizeof(ob);i++)
    	{
    		if (!living(ob[i])) continue;
    		if( !userp(ob[i]) ) continue;	
    		if( wizardp(ob[i]) ) continue;
    		for (j=0;j<sizeof(strIpAddress);j++)
    		{	
    			if (strIpAddress[j] == query_ip_number(ob[i]))
    			{
    				message_vision(HIB"\nĿǰ�ĳ�̫ӵ���ˣ�$N�����˳�ȥ��\n"NOR, ob[i]);	
    				ob[i]->move("/d/city/dating1");
    			}    			
    		}
			strIpAddress = strIpAddress + ({query_ip_number(ob[i])});
		}

		call_out("wait_fight",60);																							//һ���Ӻ��ٽ�����һ�α���

return 1;
}

int checkSameIp(object ob)
{
	int j;
	
    for (j=0;j<sizeof(strIpAddress);j++)
    {	
    	if (strIpAddress[j] == query_ip_number(ob))
    	{
    		return 1;	
    	}    			
    }
	
	return 0;
}
int do_dadu(string arg)
{
	string side,target_name,c_side,other_side,c_other_side;
	int bet_gold,gold_in;
	object gold_amount;
	object target;
	object me=this_player();
	
	if(!arg || sscanf(arg, "%s %d with %s",side,bet_gold,target_name)!=3)
    	return notify_fail("dadu <ĳ��> <����> with <ĳ��>\n");
    	if(!objectp(red_fighter) || !objectp(black_fighter))
    	return notify_fail("ѡ�ֻ�û�ϳ��������ʲô��\n");
 	
 	if(query("state")=="") return notify_fail("ѡ�ֻ�û���أ��㼱ʲô����\n");  
    	if(query("state")=="fighting") return notify_fail("�����Ѿ��ڽ������ˣ����ڲ�����Ͷע�ˣ�\n");
    	if(query("state")=="bound") return notify_fail("���ڼ����ϴα�������أ�����ż�����\n"); 
    	  	
   	target=present(target_name, environment(me));
   	if(!objectp(target))
   		return notify_fail("��Ҫ��˭��ģ�\n");
   	if(!userp(target))
   		return notify_fail("��ֻ�ܺ���Ҵ�ģ�\n");
    	if(bet_gold>500 || bet_gold<50)
    	return notify_fail("����Ҵ�ģ�����Ҫ����ʮ���ƽ����Ҳֻ����������ƽ�\n");
    	if(target->query_temp("dxdc/dadu/target")==me->query("id") && target->query_temp("dxdc/dadu/state")=="dadu") return notify_fail(target->query("name")+"�����Ѿ������ڴ�����𣿣�\n");
   	if(target->query_temp("dxdc/dadu/state")=="dadu") return notify_fail(target->query("name")+"�Ѿ��ںͱ��˴���ˣ���Ͳ�Ҫ�κ��ˣ�\n");
    	if(me->query_temp("dxdc/dadu/state")=="dadu") return notify_fail("�㲻���Ѿ��ں�"+me->query_temp("dxdc/dadu/target")+"����ˣ���\n");
    	if(side!="red" && side!="black")
    	return notify_fail("��Ҫ����һ����������\n");
    	if(side=="red") c_side=HIR"�췽"NOR; else c_side=HIB"�ڷ�"NOR;
    	if(side=="red") c_other_side=HIB"�ڷ�"NOR; else c_other_side=HIR"�췽"NOR;
    	if(side=="red") other_side="black"; else other_side="red";
   	gold_amount = present("gold_money", me);
   	if(!objectp(gold_amount))
   		return notify_fail("������ʲô�ط��ܲ�Ǯ�ģ�\n");
	gold_in=gold_amount->query_amount();
	if(gold_in<bet_gold)
		return notify_fail("û��Ǯ��ʲô��\n");   	
   
    	me->set_temp("dxdc/dadu/state","wait");
    	me->set_temp("dxdc/dadu/side",side);
    	me->set_temp("dxdc/dadu/target",target_name);
    	me->set_temp("dxdc/dadu/bet",bet_gold);
   // 	target->set_temp("dxdc/dadu/opbet",bet_gold);                                ���������bug
    
    	if(target->query_temp("dxdc/dadu/target")!=me->query("id"))
    	{
		message_vision(sprintf("$N����$n˵����"+RANK_D->query_respect(target)+"��"+RANK_D->query_self(me)+"Ը��%s���ƽ𣬶�%s��Ӯ����Ҹ��Ҷ�ô��\n",chinese_number(bet_gold), c_side), me,target);	
		me->start_busy(random(3));
		tell_object(target, YEL "������"+c_other_side+ YEL + "�������ĵĻ������Ժ�" + me->name()+ "("
				+me->query("id")+")��ģ���������루dadu "+other_side+" "+bet_gold+" with "+ me->query("id")+"�������\n"NOR
			);	
    	}
    	else
    	{
    	if(bet_gold < target->query_temp("dxdc/dadu/bet")) return notify_fail("�㲻�ܳ��ı����ٰɣ�\n");
    	if(bet_gold != target->query_temp("dxdc/dadu/bet")) return notify_fail("���˫���Ķ�ע���Ӧ����һ���ģ�\n");
    	if(side==target->query_temp("dxdc/dadu/side")) return notify_fail("�ͶԷ�����ͬһ��Ӯ���ǻ���ʲô�ɶĵģ�\n");
   		gold_amount = present("gold_money", target);
   		if(!objectp(gold_amount))
   			return notify_fail(target->query("name")+"�����Ѿ����޷����ˡ�\n");
		gold_in=gold_amount->query_amount();
		if(gold_in<bet_gold)
			return notify_fail(target->query("name")+"���ϵ�Ǯ�Ѿ�����������ˡ�\n");     	
		message_vision(sprintf("$NƳ��$nһ�ۣ�˵����"+RANK_D->query_self(me)+"�Ҹ���%s���ƽ��Ҷ�%s��Ӯ��������\n",chinese_number(bet_gold), c_side), me,target);		
		message_vision(sprintf("$N��%s����֤�𽻸��˻��ϰ壬���ϰ������˽�¶Ĳ��Ĺ�֤�ˡ�\n",chinese_number(target->query_temp("dxdc/dadu/bet"))), target);
		message_vision(sprintf("$N��%s����֤�𽻸��˻��ϰ壬���ϰ������˽�¶Ĳ��Ĺ�֤�ˡ�\n",chinese_number(target->query_temp("dxdc/dadu/bet"))), me);
		gold_amount->add_amount(-target->query_temp("dxdc/dadu/bet"));
   		gold_amount = present("gold_money", me);
		gold_amount->add_amount(-bet_gold);
		me->set_temp("dxdc/dadu/state","dadu");
		target->set_temp("dxdc/dadu/state","dadu");
    	}
  
    return 1;
	
	
	
}


int do_bet(string arg)
{
	object me;																													//�¶�ע�����
	object gold_amount;																											//������������ģ��������
	string side,c_side;
																													//�����ע��һ��
	int bet_gold;																												//�������ע���	
	me=this_player();
		
	if(!arg || !sscanf(arg, "%s %d",side,bet_gold))
                return notify_fail("yazhu <ĳ��> <����>\n");
    	if(query("state")=="") return notify_fail("ѡ�ֻ�û���أ��㼱ʲô����\n");  
    	if(query("state")=="fighting") return notify_fail("�����Ѿ��ڽ������ˣ����ڲ�����Ͷע�ˣ�\n");
    	if(query("state")=="bound") return notify_fail("���ڼ����ϴα�������أ�����ż�����\n");
  	if(side=="both" || side=="none") side="none";
    if(side=="red") c_side=HIR"�췽"NOR;
    	else  if (side=="black") c_side=HIB"�ڷ�"NOR;
    		else c_side=HIW"ƽ��"NOR;
    		
	if(side!="red" && side!="black" && side!="none" && side!="both") return notify_fail("�㵽��Ҫ����һ��Ӯ���������������\n");
	if(!objectp(gold_amount = present("gold_money", me))) return notify_fail("�����϶�ûǮ�ˣ�����ʲô����ȥ�ܵ�ɣ�\n");
	if(bet_gold<1) return notify_fail("��ѹ���Ƕ���Ǯ������ô����������\n");
	if((int)me->query_temp("dxdc/bet")+bet_gold>100) return notify_fail("���ĳ���Ȼ�Ǻ��У����䲻����ЩǮ��\n");
	if((int)gold_amount->query_amount()<bet_gold) return notify_fail("�ٺ٣����ǲ��ǿ��������ˣ��������Ǯ����ģ�\n");
	
	if(!objectp(red_fighter) || !objectp(black_fighter))
		return notify_fail("����˫����û���룬�����ע�ˣ�\n");
	
	if(!me->query_temp("dxdc/bet")) 
	{
		me->set_temp("dxdc/bet",bet_gold);
		me->set_temp("dxdc/side",side);
		message_vision(sprintf("$N�������ó�%s���ƽ�ѹ��%s�ϣ�\n",chinese_number(bet_gold), c_side), me);		
	}
	else
	{ 
		if(me->query_temp("dxdc/bet")>=100)
				return notify_fail("��λү���������ע�Ѿ��ﵽ���������ˣ��ټ����ǿɳ��ܲ����ˡ�\n");
		if(me->query_temp("dxdc/side")!=side)
				return notify_fail("����ɲ�׼һ����ͬʱ����������Ӯ��\n");
		me->add_temp("dxdc/bet",bet_gold);
		message_vision(sprintf("$N���������ó�%s���ƽ�׷ѹ��%s�ϡ�\n",chinese_number(bet_gold), c_side), me);		
	}
	gold_amount->add_amount(-bet_gold);
    	me->start_busy(1);
	add(side+"_money",bet_gold);
	add("yingyu",bet_gold*100);
	
	
	if(query("red_money") && query("black_money"))
	{ 
	if(query("red_money") / query("black_money")>=5){													//�趨�ĳ�������
		set("black_betrate",(query("red_money") / query("black_money") - 1.5)*100);
		if (query("black_betrate") > 2000)
			set("black_betrate",2000);
	}
	else
		if(query("red_money") / query("black_money")>=2)
			set("black_betrate",140);
		else
			set("black_betrate",130);
	if(query("black_money") / query("red_money")>=5){
		set("red_betrate",(query("black_money") / query("red_money") - 1.5)*100);
		if (query("red_betrate") > 2000)
			set("red_betrate",2000);
	}
	else
		if(query("black_money") / query("red_money")>=2)
			set("red_betrate",140);
		else
			set("red_betrate",130);			
	}
    
	return 1;	
}


int valid_leave(object me, string dir)
{
	if (( me->query_temp("dxdc/bet") || me->query_temp("dxdc/dadu/state")=="dadu") && dir == "up" )
		return notify_fail("��ô���������������˾��뿪����Һú����ſ�������\n");
	if (userp(me) && !wizardp(me))
		strIpAddress = strIpAddress - ({query_ip_number(me)});
	

	return ::valid_leave(me, dir);
}

object query_red_fighter()
{
	return red_fighter;
}

object query_black_fighter()
{
	return black_fighter;
}