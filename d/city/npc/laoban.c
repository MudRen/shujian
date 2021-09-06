// laoban.c		���¶ĳ��ϰ�
// created by kaol 2003/9/27
// modified by campsun 2003/9/28

#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
inherit F_BANKER;

int ask_match();
int ask_gold();
int ask_betrate();
int ask_convert();

void create()
{
    set_name( "�Ƹ���", ({ "huang fuba","huang","fuba" }) );
    set("gender", "����");
    set("title", HIB"���º�ȭ�м����Ǯׯͷ���ϰ�"NOR);
    set("age", 45);
    set("long", "������������εĵ��º�ȭ�м����Ǯׯͷ���ϰ塣\n"
				"��˫ĿԲ�����侲�ش�����Χ��ȭ����ÿһ���ˡ�\n"
				"���ĺ������������ں�����ȭ�ֵ�������\n"
				"��������������йر����Ľ�չ���(match)�Լ�ѹע�����(gold)��\n"
				);
        set("unique", 1);
        set("no_bark", 1);
        set("job_npc", 1);
        set("no_ansuan", 1);
        set("get", 1);

	set("str", 30);
    	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 7);
	set("qi", 500); 
	set("max_qi", 500);
	set("jing", 100);
	set("max_jing", 100);
	set("shen", 0);
	set("shen_type", 1);
	set_skill("unarmed",100);
	set_skill("dodge",100);
	set("combat_exp", 100000);
	        set("vendor_goods", ({
    	(["name":__DIR__"obj/jitui","number":30]),
    	(["name":__DIR__"obj/jiudai","number":10]),
    	(["name":__DIR__"obj/hdjiudai","number":10]),
    	(["name":__DIR__"obj/kaoya","number":20])
        }));

    	set("attitude", "peaceful");
    	set("inquiry", ([
		"name" : "�����һ�ĳ�˵Ĵ����Ƹ��ԣ�������˭�˲�֪��˭�ϲ�������",
		"here" : "�����ȭ�в����ۣ�����ȭ�Ŀɶ��ǽ����ϸ������ɵĸ��ְ���",	
		"rumors" : "���Ƕ��Ǵ󺺰��գ�������ɽȴ������ռ�ˣ�����һ�գ�Ҫ������ɱ�øɸɾ�����",
		"����" : (: ask_match :),
		"match" : (: ask_match :),
		"gold" : (: ask_gold :),
		"�Ľ�" : (: ask_gold :),
		"����" : (: ask_betrate :),
		"betrate" : (: ask_betrate :),
	]));

     setup();

     carry_object(__DIR__"obj/b_cloth")->wear();
     carry_object(__DIR__"obj/blade")->wield();
}

void init()
{
        object ob = this_player();
        if (base_name(environment()) != query("startroom")) return;

        ::init();
		if( interactive(ob = this_player()) && visible(ob) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_buy", "buy");
        add_action("do_list", "list");
        add_action("do_check", ({"check", "chazhang", "����"}));
	add_action("do_convert", ({"convert", "duihuan", "�һ�"}));
	add_action("do_deposit", ({"deposit", "cun", "��"}));
	add_action("do_withdraw", ({"withdraw", "qu", "ȡ"}));

}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
		message_vision("�Ƹ��Զ�$N�Թ��˹��ֵ���������������˼�λ�����ϸ������ɵĸ���ǰ����ȭ��������ע�ɣ�\n", ob);
		return;
}

void relay_say(object me, string msg)
{
        if (!msg) return;
        if (random(50)==0){
        	switch(random(3)) {
                        case 0:         
                               	command("hi " + me->query("id"));  
                                break;
                        case 1: 
                                command("push " + me->query("id"));  
                                break; 
                        case 2:         
                                command("wah " + me->query("id"));  
                                break; 
                        default:
          	}
    	}
}

void relay_emote(object me, string arg)
{
        switch (arg) {
                case "die":
                case "idle":
                case "sure":
                case "lazy":
                case "xbc97":
                case "smell":
                case "bored":
                case "escape":
                case "chicken":
                case "laughproud":
                case "nonsense":
                        command(arg);
                        break;
                case "waggle":
                case "willbe":
                case "pain":
                case "push":
                case "puke":
                case "poke":
                case "stare":
                case "admit":
                case "rascal":
                case "story":
                case "crazy":
                case "thank":
                case "disapp":
                case "disapp1":
                case "accuse":
                case "homework":
                case "papaya":
                case "benger":
                case "sue":
                case "regard":
                case "courage":
                case "meeting":
                case "pat":
                case "pig":
                case "piggy":
                case "flower":
                case "joke":
                case "sigh":
                case "poor":
                case "ugly":
                case "rabbit":
                case "pretty":
                case "knife1":
                case "grpfight":
                case "points":
                case "congra":
                case "sing3":
                case "lover":
                case "nocry":
                case "flatter":
                case "rabbit2":
                case "goodkid":
                case "fire":
                case "boat":
                        command(arg + " huang");
                        break;
                case "interest":
                        command("liar");
                        break;
                case "slow":
                        command("lover");
                        break;
                case "shout":
                        command("peace");
                        break;
                case "bug":
                case "cook":
                command("taste");
                        break;
                case "hero":
                case "hehe":
                        command("fear");
                        break;
                case "cold":
                case "sing2":
                case "magic":
                case "taste":
                        command("escape");
                        break;
                case "inn":
                case "sorry":
                case "careful":
                        command("sneer");
                        break;
                case "kick":
                case "slap":
                case "trip":
                        command("pain");
                        break;
                case "fire1":
                case "swear":
                        command("shake");
                        break;
                case ":)":
                case "haha":
                case "xixi":
                case "laugh":
                case "hehehe":
                case "giggle":
                        command("nosmile");
                        break;
                case "claw":
                        command("cry");
                        break;
                case "!!!":
                case "gun":
                case "club":
                case "hug":
                case "drug":
                case "doubt":
                case "makeup":
                        command("corpse huang");
                        break;
                case "shameless":
                        command("hate huang");
                        break;
                case "admire":
                        command("humble huang");
                        break;
                case "joythank":
                        command("thank huang");
                        break;
                case "rhero":
                        command("shout huang");
                        break;
                case "poem":
                        command("raise huang");
                        break;
                case "slogan":
                        command("slogan2 huang");
                        break;
                case "angry":
                        command("stare huang");
                        break;
                case "happy":
                        command("rich huang");
                        break;
                case "dare":
                        command("points huang");
                        break;
                case "lick":
                        command("smell huang");
                        break;
                case ":(":
                case "cry":
                        command("nocry " + me->query("id"));
                        break;
                case "xigua":
                        command("xigua2 " + me->query("id"));
                        break;
                case "nod":
                        command("shake " + me->query("id"));
                        break;
                case "shake":
                        command("nod " + me->query("id"));
                        break;
                case "blush":
                        command("lover " + me->query("id"));
                        break;
                case "monk":
                        command("buddhi " + me->query("id"));
                        break;
                case "hungry":
                        command("rich " + me->query("id"));
                        break;
                case "slapsb":
                        command("inn " + me->query("id"));
                        break;
                case "wait":
                        command("nomatch " + me->query("id"));
                        break;
                case "lean":
                        command("hug " + me->query("id"));
                        break;
                case "god":
                        command("comfort " + me->query("id"));
                        break;
                case "faint":
                        command("nofear " + me->query("id"));
                        break;
                case "wanfu":
                        command("bow " + me->query("id"));
                        break;
                case "innocent":
                        command("goodman " + me->query("id"));
                        break;
                case "yawn":
                        command("zzz " + me->query("id"));
                        break;
                case "visit":
                        command("welcome " + me->query("id"));
                        break;
                case "welcome":
                        command("visit " + me->query("id"));
                        break;
                case "brag":
                        command("gun " + me->query("id"));
                        break;
                case "dunno":
                        command("disapp " + me->query("id"));
                        break;
                case "hmm":
                        command("? " + me->query("id"));
                        break;
                case "poem3":
                        command("willbe " + me->query("id"));
                        break;
                case "zzz":
                        command("shutup " + me->query("id"));
                        break;
                case "nomatch":
                        command("mother " + me->query("id"));
                        break;
                case "nofear":
                        command("chicken " + me->query("id"));
                        break;
                case "meet":
                case "smell1":
                        command("seduce " + me->query("id"));
                        break;
                case "rose":
                case "kiss":
                        command("yeah " + me->query("id"));
                        break;
                case "rich":
                case "protect":
                        command("joythank " + me->query("id"));
                        break;
                case "hammer":
                case "killair":
                        command("peace " + me->query("id"));
                        break;
                case "uncle":
                case "anniversary":
                        command("sure " + me->query("id"));
                        break;
                case "cut":
                case "corpse":
                case "soup":
                case "smash":
                case "slash":
                case "knife":
                        command("peace1 " + me->query("id"));
                        break;
                case "thumb":
                case "mother":
                case "praise":
                case "goodman":
                case "applaud":
                case "handsome":
                        command("noshame " + me->query("id"));
                        break;
                case "bf":
                case "gf":
                case "chitchat":
                        command("nonsense " + me->query("id"));
                        break;
                case "wave":
                case "bye":
                case "byebye":
                case "goodbye":
                        command("byebye " + me->query("id"));
                        break;
                case "rob":
                case "fat":
                case "zhu":
                case "dumb":
                case "uncle":
                case "u&me5":
                case "congra1":
                case "marriage":
                        command("faint " + me->query("id"));
                        break;
                case "love":
                case "lovelook":
                case "loveshoe":
                case "deadlove":
                case "ghostlove":
                case "joycup":
                case "touch1":
                case "wink":
                case "u&me2":
                case "xigua2":
                case "sex":
                case "seduce":
                case "doufu":
                case "oath":
                case "flirt":
                        command("puke " + me->query("id"));
                        break;
                case "nosmile":
                case "brother":
                case "massage":
                        command("goodkid " + me->query("id"));
                        break;
                case "ysis":
                case "sister":
                case "aunt":
                case "18mo":
                case "beauty1":
                case "shajiabang1":
                        command("uncle " + me->query("id"));
                        break;
                case "bite":
                case "grin":
                case "hate":
                case "consider":
                        command("fear " + me->query("id"));
                        break;
                case "flush":
                case "u&me1":
                case "callname":
                        command("shout " + me->query("id"));
                        break;
                case "agree":
                case "u&me":
                case "raise":
                        command("raise " + me->query("id"));
                        break;
                default:
                        command(arg + " " + me->query("id"));
                        break;
        }
}
int ask_gold()
{
	object ob=this_object();
	object me=this_player();
	object room=environment(ob);
	string str_temp;
	int money_gold;
	int money_silver;
	tell_object(me,"�����䳡Ŀǰ������£�\n");
	switch(room->query("state"))
	{
		case "bound":
		break;
		default:
	
	tell_object(me,RED"�췽"NOR+"���ܶĽ�Ϊ��"HIY+chinese_number(room->query("red_money"))+NOR"���ƽ�\n");
	tell_object(me,BLU"�ڷ�"NOR+"���ܶĽ�Ϊ��"HIY+chinese_number(room->query("black_money"))+NOR"���ƽ�\n");
	tell_object(me,HIW"ƽ��"NOR+"���ܶĽ�Ϊ��"HIY+chinese_number(room->query("none_money"))+NOR"���ƽ�\n");

	if(room->query("red_betrate") && room->query("black_betrate"))
	{
		tell_object(me,"�Ƹ���˵�����ⳡ���������ĿǰΪ��\n");
		tell_object(me,HIR"�췽"NOR+"��100:"+room->query("red_betrate")+HIB"          �ڷ�"NOR+"��100:"+room->query("black_betrate")+HIW"          ƽ��"NOR+"��100:"+room->query("none_betrate")+"\n");
	}
	if (me->query_temp("dxdc/bet"))
	{
		tell_object(me,"��Ŀǰѹ����");
			if(me->query_temp("dxdc/side")=="red")
				tell_object(me,HIR"�췽��"NOR);
			else
				if(me->query_temp("dxdc/side")=="black")
					tell_object(me,HIB"�ڷ���"NOR);
				else
					tell_object(me,HIW"ƽ�� ��"NOR);
		tell_object(me,HIY+chinese_number(me->query_temp("dxdc/bet"))+NOR"���ƽ�\n");
	}
	else
	{
		tell_object(me,"����û��ע�ء�ѡ���˾͸Ͻ���ע�ɣ�����ɲ����˰���\n");
	}
}//end switch
	if(room->query("yingyu")<0)
	{
		money_gold=-room->query("yingyu")/100;
		money_silver=-room->query("yingyu") % 100;
	}
	else
	{
		money_gold=room->query("yingyu")/100;
		money_silver=room->query("yingyu") % 100;
	}
	str_temp="�����䳡Ŀǰӯ��״��Ϊ��";
	if (room->query("yingyu")<0) 
		str_temp+="���� "; 
	else 
		if (room->query("yingyu")>0)
			str_temp+="ӯ�� ";
		else
			str_temp+="ƽ��";
			
	if (money_gold) str_temp+=HIY+chinese_number(money_gold)+"���ƽ�"NOR;
	if (money_silver) str_temp+=HIW+chinese_number(money_silver)+"������"NOR;
	str_temp+="��\n";
	
	tell_object(me,str_temp);
	
	return 1;

}
int ask_match()
{
	object me,room,red,black;
	string str_msg="";
	me = this_player();
	room = environment(this_object());
	red = room->query_red_fighter();
	black = room->query_black_fighter();
	

	if(room->query("state")=="") 
	{
		tell_object(me,"�Ƹ�����Ƿ��Ƿ����������ѡ�����ں�̨׼���������ǳ������԰����꣡\n");
		return 1;
	}
	if(room->query("state")=="wait" || room->query("state")=="fighting")
	{
		if (!objectp(red))
		{
			tell_object(me,"�췽ѡ�������Ӳ��ܳ�ϯ�������ⳡ����ȡ���ˡ�\n");
			return 0;
		}
		if (!objectp(black))
		{
			tell_object(me,"�ڷ�ѡ�ָղ�Ť���˽ţ����ܲμӱ����ˡ��ⳡ����ȡ���ˡ�\n");					//һ�㲻�ᷢ�����������
			return 0;
		}
		str_msg+="���������˫��������"HIW+red->query("family/family_name")+NOR"��"RED+red->query("name")+NOR"������"HIW+black->query("family/family_name")+NOR"��"BLU+black->query("name")+NOR"!\n";
		str_msg+="����"RED+red->query("name")+NOR"��"HIY+red->query("good_skills")+NOR"��"BLU+black->query("name")+NOR"��"HIY+black->query("good_skills")+NOR"�ǿɶ��ǽ����Ϻպ������ľ�������\n";
		str_msg+="��ֱ���";
		if(!room->query("use_weapon")) str_msg+=HIC"������ʹ�ñ�����"NOR;
		else str_msg+=HIC"����ʹ�ñ�����"NOR;
		switch(room->query("base_jiali"))
		{
			case 0:
				str_msg+=HIB"��ʹ���������������ಫ��\n"NOR;
			break;
			case 10:
				str_msg+=HIB"ʹ��ȫ�����������ಫ��\n"NOR;
			break;
			default:
				str_msg+="ʹ��"HIW+chinese_number(room->query("base_jiali"))+"������"NOR+"���������ಫ!\n";
		}
	switch(room->query("state"))
	{
		case "wait":
			tell_object(me,"�Ƹ��Ը�æ������˵������������ѡ���Ѿ��ǳ��ˣ�����������ʼ��Ҫ��עץ���ģ�\n");
			tell_object(me,str_msg);
			return 1;
		break;
		case "fighting":
			tell_object(me,"�Ƹ��Բ��ͷ��ػ��˻��ֵ��������Ѿ���ʼ�ˣ���ר�Ŀ��ɣ���Ȼ�����˿ɱ���ң�\n");
			tell_object(me,str_msg);
			return 1;
		break;
	}//end switch
	}//end if
	tell_object(me,"�Ƹ���ת������˵�������������Ѿ�������Ҫ���³����Ժ�\n");
	return 1;
}
int ask_betrate()
{
	object me=this_player();
	object room=environment(this_object());
	if(room->query("red_betrate") && room->query("black_betrate"))
	{
		tell_object(me,"�Ƹ���˵�����ⳡ���������ĿǰΪ��\n");
		tell_object(me,HIR"�췽"NOR+"��100:"+room->query("red_betrate")+HIB"          �ڷ�"NOR+"��100:"+room->query("black_betrate")+"\n");
		return 1;
	}
	tell_object(me,"�Ƹ��Զ�ݺݵĿ����㣺���������ʶ��ٹ���ʲô�£�\n");
	return 1;	
}
int ask_convert()
{
	object silver_amount;
	object gold_amount;
	object me=this_player();
	int silver_in;
	tell_object(me,"�Ƹ��Զ���˵�����һ�������ϵ����а���ȫ�һ��ɻƽ�ġ�\n");
	silver_amount = present("silver_money", me);
	if(!objectp(silver_amount))
	{
		tell_object(me,"�Ƹ��Զ���˵���������ϸ���û�а���������һ�ʲô��\n");
		return 1;
	}
	silver_in=silver_amount->query_amount();
	if(silver_in<100)
	{
		tell_object(me,"�Ƹ��Զ���˵���������ϵİ�������һ�������ܶһ��ɻƽ�\n");
		return 1;
	}
	silver_amount->add_amount(-silver_in/100*100);
	gold_amount = present("gold_money", me);
	if(objectp(gold_amount))
	{
		gold_amount->add_amount(silver_in /100);
	}
	else
	{
   		gold_amount=new("/clone/money/gold");
 		gold_amount->set_amount(silver_in / 100);
   		gold_amount->move(me);
	}
	tell_object(me,"�Ƹ��Զ���˵�������Ѿ��������ϵ�"+chinese_number(silver_in/100*100)+"��"+HIW"����"NOR+"�һ���"+chinese_number(silver_in/100)+"��"+HIY"�ƽ�"NOR+"��\n");
	
	return 1;
	
	
	
}
void kill_ob(object ob)
{
        ob->remove_killer(this_object());
        remove_killer(ob);
        command("swear");
}

void unconcious()
{
        say("�Ƹ��Դ��һ��: ��ѽ!������\n");
        reincarnate();
        set("eff_qi", query("max_qi"));
        set("qi", query("max_qi"));
        set("eff_jing", query("max_jing"));
        set("jing", query("max_jing"));
        set("jingli", query("eff_jingli"));
        clear_conditions_by_type("poison");
}

void die()
{
        unconcious();
}