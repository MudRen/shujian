//weixiaobao.c
//Ŀǰû�м��Ϲ�������ƣ��ȴ����Ϥ����������
#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

#define WEAPON_P(i) "/d/city/weapon/weapon"+i
#define WEAPON_TOTAL 15
#define WEAPON_LESS 10
#define WEAPON_NUMBER 3
#define UPDATE_TIME 1

void born_weapon();
void check_time();
void start_weapon();
int born_file(string file);
string ask_tdh1();
string ask_tdh2();
string ask_tdh3();
string ask_tdh4();
string ask_fight();
int do_yes(string arg);

int move_other(string place);
int ask_jiebai();


//ذ�ס����¡��ɺ�ҩ������С����ΤС�����ؼ汸�����󷨱���
void create()
{
        set_name("ΤС��", ({ "wei xiaobao", "wei", "xiaobao" }));
        set("title",HIM"¹����"NOR);
        set("nickname",HIW"С����"NOR);
        set("shen_type", 1);

        set("gender", "����");
        set("no_ansuan",1);        
        set("age",22);  
        set("str",10);
        set("con",20);
        set("int",50);
        set("dex",30);
        set("kar",100);
        set("per",30);
        set("pur",5);       
        set("long",
"    ˿���������У����������չ���������������д�š���Զ�󽫾�Τ����
���������д�š�����¹����Τ����������������ӵ��һλ���꽫�����������
��λ����ͷ���춥�ӣ�������ӣ�ü����Ц����߯���⣬������ҡ���ȣ���
�����֮�������ֵ��ϴ󵶣�ٲȻ����֮��������Τ��С����Ҳ��

        ���Ŵ��˼�������������Գ��Խύ���ˡ�
        ");
        set_skill("unarmed", 20);       
        set_skill("dodge", 900);
        
        set_skill("youlong-shenfa",901);
        set_skill("dulong-dafa",101);
        
        map_skill("force","dulong-dafa");
        map_skill("dodge","youlong-shenfa");
                
        set("max_neili",9000);
        set("max_jingli",9000);        
        
        set_temp("apply/damage", 15);
        
        set("combat_exp", 4000);
        set("attitude", "friendly");
                
        set("chat_chance", 1);
        set("quest/baibian",1);
        set("move_seller",1);
        // ΤС��
        set("chat_msg", ({      
        (: move_other("") :),
        "ΤС�������˵����ذ�ס����¡��ɺ�ҩ��������С����ΤС�����ؼ汸�����󷨱���\n",
        "ΤС���������ֵܽ�������\n",
        "ΤС���������ɷ�һ�Լȳ���ʲô����׷����˵���Ļ������ز����ڵġ�\n",
        "ΤС����һ�����������裡\n",
                
        }) );
        set("inquiry", ([
                "name": "�Ҿ��Ǵ����ղ�󳼡������������󳼡�������Ӫ���������޶�ͳ���մͰ�ͼ³�ºš��ʹ�����ӡ�һ��¹������",
                "����": "��ʵ�һ�����ػ��ܶ����½������ҵ��ӣ���ľ��������",
                "������":"��С�������������̰���ʹ��",
                "��������":"��֪��ʦ���տɺá�",
                "����":"���Ŷ��ˣ��鷳����Ҳ�ࡣ",
                "18mo":"�ǻ������ҵ�ר����", 
                "dazao":"�㻹��ȥ��Τ�������ɡ�", 
                "weilan":"��������������ı��������ߣ�������ı������������ҵġ�", 
                "Τ��":"��������������ı��������ߣ�������ı������������ҵġ�", 
                "���":(: ask_jiebai :),
                "�½���":"��ƽ��ʶ�½��ϣ����Ӣ��Ҳ��Ȼ��",
                "éʮ��":"��֪��ʮ�˸��������ˡ�",
                "����":"����������",
		"˫��":"���������ţ�Ŀǰ�����ݣ�",
                "��ػ�":(: ask_tdh1 :),
                "С����":"С������Ҳ������ǰ��С�����ˡ�", 
                "Τ����":"�������������ô��ʶ�ģ�",  
                "����Ժ":"�п�ȥ��������������ĳ���",    
                "�ų��󺣣����Ӻ�ˮ������":(: ask_tdh2:),
                "��ľ��":(: ask_tdh3:),
                "����": (:ask_fight:),
         ]));        
        setup();
        if(clonep())
        {
        	start_weapon();
        	carry_object(__DIR__"obj/huangmagua")->wear();
        }
}

//���Ի�����
string ask_tdh1()
{
	command("say");
	this_object()->set_temp("wei_ask_tdh",1);
	return "����߸ԣ�һ��Ϫɽǧ���㡣";	
}
string ask_tdh2()
{
	if (this_object()->query_temp("wei_ask_tdh") == 1 )
	{
	command("touch "+this_object()->query("id",1));
	this_object()->set_temp("wei_ask_tdh",2);
	return "�컨ͤ����һ�ã�";
	}
	else return 0;
}
string ask_tdh3()
{
	if (this_object()->query_temp("wei_ask_tdh") == 2 )
	{		
		command("cat "+this_player()->query("id",1));
		this_object()->delete_temp("wei_ask_tdh");
		return "ԭ���Ǳ����ֵܰ�";
	}
	else return 0;
}


void relay_emote(object ob, string verb)
{
       if( !userp(ob) ) return;
	switch(verb) {

	case "kiss1":
	case "love":
	case "kiss":
	case "taste":
	case "rose":
	case "boat":
	case "18mo":
	case "ysis":

	if ( (string) ob -> query ("gender") == "����")
	{
	command ("say ��������"+ ob->query("name") + "������ͬ־����\n") ;
	command ("say ��Ӵ��" + RANK_D->query_rude(ob)+"�����߸����ţ��㲻֪����");
	}
	if (ob->query("gender") == "Ů��" && ( ob->query_per() > 30 || ob->query("age") < query("age") ) )
	{
	command("18mo");
	message_vision("\nΤС����$NЦ��������Ȼ���кܶ����ţ�����һ���ֺη�������\n", ob);
	command("consider");
	}
	if (ob->query("gender") == "Ů��" && ( ob->query_per() < 15 || ob->query("age") > 50 ) )
	{
	command("bite");
	message_vision("\nΤС����$NЦ������������̫���ˣ��ѵ��һ�����Ȥ����\n", ob);
	command("disapp " + ob->query("id"));
	}

	break;
       default:
       if( random(10)<2 )
       {
	command(verb + " " + ob->query("id"));
	return;
       }
       else
	{
	switch(verb)
	{
	case  "nod":
	case  "smile":
	case  "hehe":
	case  "water":
	case  "snow":
	case  "club":
	case  "haha":
	case  "die":
	case  "kick":
	case  "corpse":
	case  "rich":
	case  "hi":
	case  "puke":
	case  "faint":
	case  "escape":
	case  "raise":
	case  "bite":
	case  "knife":
	case  "drug":
	case  "cook":
	case  "shutup":
	case  "slogan2":
	case  "slap":
	case  "sing":
	case  "sigh":
	case  "shout":
	case  "sister":
   switch(random(50))
   {
    case 0:
    command ("kick "+ ob->query("id"));
    command ("hehe");
    break;
    case 1:
    command ("club "+ ob->query("id"));
    command ("hehe");
    break;
    case 2:
    command ("drug2 "+ ob->query("id"));
    break;
    case 3:
    command ("smile");
    command ("cook "+ ob->query("id"));
    break;
    case 4:
    command ("smash "+ ob->query("id"));
    break;
    case 5:
    command ("knife "+ ob->query("id"));
    command ("sister "+ ob->query("id"));
    break;
    case 6:
    command("cry");
    command("say ����"+ob->query("name")+"��"+RANK_D->query_rude(ob)+"��Ȼ���һ�����\n");
    break;
    case 7:
    command ("shutup ");
    command ("shutup "+ ob->query("id"));
    break;
    case 8:
    command("cry");
   command ("corpse "+ ob->query("id"));
    break;
    case 9:
    command ("bug "+ ob->query("id"));
    break;
    case 10: 
    command ("brag "+ ob->query("id"));
    break;
    case 11: 
    command ("bite");
    command ("shout "+ ob->query("id"));
    break;
    case 12: 
    command ("shake");
    break;
    case 13: 
    command ("stare "+ob->query("id"));
    command ("hit "+ ob->query("id"));
    break;
    case 14: 
    command ("sneer");
    break;
    case 15: 
    command ("faint");
    break;
    case 16: 
    command ("ah");
    break;
    case 17: 
    command ("ysis "+ob->query("id"));
    command ("hehe");
    break;
    case 18: 
    command ("blush");
    break;
    case 19: 
    command ("walkby");
    break;
    case 20: 
    command("18mo");
    break;
    case 21: 
    command ("noway");
    break;
    case 22: 
    command ("cry");
    break;
    case 23:
    command ("pig");
    command ("corpse "+ob->query("id"));
    break;
    case 24: 
    command ("careful");
    break;
    case 25: 
    command ("zzz "+ob->query("id"));
    break;
    case 26:
    command ("praise");
    command ("faint");
    break;
    case 27: 
    command ("poem "+ob->query("id"));
    break;
    case 28: 
    command ("rascal "+ob->query("id"));
    break;
    case 29: 
    command ("meeting "+ob->query("id"));
    command ("die "+ob->query("id"));
    break;
    case 30:
    command("giggle "+ob->query("id"));
    break;
    case 31:
    command("cut");
    break;
    case 32: 
    command ("sing3") ;
    break;
    case 33: 
    command ("escape "+ ob->query("id"));
    break;
    case 34:
    command("faint "+ob->query("id"));
    break;
    case 35: 
    command ("kick "+ ob->query("id"));
    command ("dead");
    break;
    case 36:
    command ("slap "+ ob->query("id"));
    command ("hehe");
    break;
    case 37: 
    command("faint");
    break;
    case 38: 
    command ("laugh "+ ob->query("id"));
    break;
    case 39: 
    command("hero");
    break;
    default:
       if( random(10)<3 )
       {
	command(verb + " " + ob->query("id"));
	return;
       }
       break;
   return;
   }
	case "kiss1":
	case "sister":
	case "jump":
	case "love":
	case "lovelook":
	case "praise":
	case "visite":
	case "drinkcup":
	case "goodkid":
	case "pat":
	case "addoil":
	case "laughproud":
	case "smile":
	case "xixi":
	case "hehe":
	case "giggle":
	case "thumb":
	case "admire":
	case "applaud":
	case "hi":
	case "love":
	case "sigh":
	case "haha":
   switch(random(35))
   {
    case 0: 
    command ("pat "+ ob->query("id"));
    break;
    case 1: 
    command ("hmm");
    break;
    case 2: 
    command ("praise "+ ob->query("id"));
    break;
    case 3: 
    command ("xixi");
    break;
    case 4: 
    command("say "+ob->query("name")+"��˵�û��Һ�ϲ������\n");
    command ("grin "+ ob->query("id"));
    break;
    case 5: 
    command("say "+ob->query("name")+"�����Ҹ������ٵ�����\n");
    command ("goodkid "+ ob->query("id"));
    break;
    case 6:
    command ("pat "+ ob->query("id"));
    break;
    case 7: 
    command("say "+ob->query("name")+"��������һ��ȥ�ʹ�����\n");
    command ("haha");
    break;
    case 8:
    command ("wink "+ ob->query("id"));
    break;
    case 9:
    command ("laughproud "+ ob->query("id"));
    break;
    case 10:
    command("say "+ob->query("name")+",��С�ӣ�������ǰ;��\n");
    command ("thank");
    break;
    case 11: 
    command ("nod");
    command ("xixi");
    break;
    case 12:
    command ("shake");
    break;
    case 13:
    command("say "+ob->query("name")+",������գ�\n");
    command ("push "+ob->query("id"));
    break;
    case 14: 
    command ("xixi");
    break;
    case 15:
    command ("lovelook "+ob->query("id"));
    break;
    case 16:
    command ("smile "+ob->query("id"));
    break;
    case 17:
    command("say �ã��ã��»������迪�ĵ꣬�Ҹ������ۣ�\n");
    command ("kiss "+ob->query("id"));
    break;
    case 18:
    command ("addoil "+ob->query("id"));
    break;
    case 19:
    command ("xixi");
    break;
    case 20:
    command ("handshake "+ob->query("id"));
    break;
    case 21:
    command ("puke "+ob->query("id"));
    break;
    case 22:
    command ("touch "+ob->query("id"));
    break;
    case 23:
    command ("mimi");
    break;
    case 24:
    command ("slap "+ob->query("id"));
    break;
    case 25:
    command ("thumb "+ob->query("id"));
    break;
    case 26:
    command ("applaud ");
    break;
    case 27:
    command ("hi");
    break;
    case 28:
    command ("hi "+ob->query("id"));
    break;
    case 29:
    command("say ��С����ô������̫û��ûС�ɣ�\n");
    command("angry");
    break;
    default:
    command(verb + " " + ob->query("id"));
    command("smile");
    break;
   return;
   }
  return;
  }
}
}
return;
}
int ask_jiebai()
{
        object ob;
        int i;
        string str;
        
        ob = this_player();
        str = RANK_D->query_respect(ob);
        
        if(ob->query("quest/wxbjiebai"))
        {
        	command("say ���ǲ��ǽ�ݹ���ô��");
        	return 1;
        }                
        if (!intp(i = ob->query_temp("give_wei_money_gived") ) ) i = 0;
        switch(i){
                case 0:str = "��λ"+str+"���ҳ��μ��棬�����Է�������˭����֪���ɣ�";break;
                case 1:str = "���ǻ���Ҫ����׽��׽�Ŷ";break;
                case 2:str = "�����п�����ȥ����˵�鰡ʲô�ģ��Ǻ�";break;
                case 3:str = "����������Ц���Ű����㻹���氡��";break;
                default:str = "�����Ĳ���";break;
        }
        command("say "+str);
        return 1;
}

int move_other(string place)
{
        string *places = ({"/d/city/lichunyuan","/d/dali/dalics","/d/emei/qingyinge","/d/foshan/kedian","/d/fuzhou/zhengting","/d/hengshan/baiyunan","/d/hz/tianxiang","/d/suzhou/canglangting","/d/xiangyang/cross1"});       
        object me = this_object();
                
        tell_room(environment(me),"ͻȻԶ������һ�����Ϲ�������,"+me->name()+"��ಡ��Ĳ�֪��ȥ�����ˡ�\n");
        if (place=="") me->move(places[random(sizeof(places))]);
        else me->move(place);
        tell_room(environment(me),me->name()+"ͻȻ��֪�������������������������ǰ��\n");
        set("startroom",base_name(environment()));
        return 1;
}

int accept_object(object who, object ob)        
{
        
        if (ob->query("money_id"))
        {
                if ( ob->value() < 500000 )
                {
                        command("? "+who->query("id",1));
                        command("say �����ʲô��");
                        return 0;               
                }
                command("hehe");
                //����ͼ���� �ٺ�
                if (who->query_temp("give_wei_money_times") < 2 )
                {
                        if ( !who->query_temp("give_wei_money_times") ) who->set_temp("give_wei_money_times",1);
                        else who->add_temp("give_wei_money_times",1);
                        switch( who->query_temp("give_wei_money_times") )
                        {
                                case 0:command("say ����ô����˼�أ�");break;
                                case 1:command("say ����ô����˼�أ�");break;
                                case 2:command("say ��ô���أ�����ðɣ�");break;                               
                        }                       
                        return 0;
                }
                who->delete_temp("give_wei_money_times");
                //��ĳЩquest
                if (!who->query_temp("give_wei_money_gived")) who->set_temp("give_wei_money_gived",1);
                else who->add_temp("give_wei_money_gived",1);
                //haha
                command("say �Ǿ�ֻ�й�����������ˣ�");
                call_out("destroying", 1, ob);
                return 1;               
        }
        else {
                command("en "+who->query("id",1));
                return 0;
                }
}

void destroying(object ob)
{     
       if (!ob) return;
       if (userp(ob)) command("drop "+ob->parse_command_id_list()[0]);
        else destruct(ob);
}

int accept_fight(object ob){
        command("cry2");
        return 0;
}


void init()
{
        object  ob;
        
        add_action("do_list", "list");
        add_action("do_buy", "buy");
        add_action("do_look","look");
        add_action("do_yes","yes");
        ::init();
        
         if( interactive(ob = this_player()) && visible(ob) && userp(ob) ){
                if (ob->query("gender") == "Ů��" && ( ob->query_per()>30 || ob->query("age")<query("age") ) )
                command("18mo "+ob->query("id"));
                else command("look "+ob->query("id"));
                }
}
int do_yes(string arg)
{
	object me = this_player();
	if(!me->query_temp("quest/baibian_ok")) return 0;
	
	me->delete_temp("quest/baibian_ok");
	me->delete_temp("quest/baibian");
	
	message_vision("$N�����뻹�����˰ɡ�\n",me);
	command("hehe");
	message_vision("$N��$n������ѵ��ϵ�"HIG"��Ʊ"NOR"�������������Լ����\n",this_object(),me);
	message_vision(CYN"$N�������ĵĽ�һЩ�����аٱ䡿�ľ��ϴ��ڸ���$n��\n"NOR,this_object(),me);
	me->set("quest/baibian",1);
	log_file("quest/baibian",sprintf("%-8s(%-8s) �ɹ���ΤС������������аٱ䡣",me->query("name"),getuid(me)),this_object() );
	//set
	command("look "+getuid(me));
	if(random(me->query("pur"))<10
	&& random(me->query("kar"))>10
	&& random(me->query("combat_exp"))>200000
	&& me->query("gender")!="����"
	)
	{
		string str ="�ֵ�";
		if(me->query("gender")=="Ů��")
		{
			str = "���";
			if(me->query("age") <= query("age")) str ="����";			
		}
		command("say ��λ"+RANK_D->query_respect(me)+"���Ƕ��˱���ݰ������˽���"+str+"���˺����Ƕ����и���������ͬ������Ըͬ��ͬ��ͬ��������Ըͬ��ͬ��ͬ������");
		message_vision("$Nһ������$n������������ݣ���Ϊ"+str+"��\n",this_object(),me);
		command("say �Ժ���������ҵı������⣬�Ҿ͸����Żݡ�");
		command("laughproud "+getuid(me));
		me->set("quest/wxbjiebai",1);		
		log_file("quest/baibian",sprintf("%-8s(%-8s) �ɹ���ΤС����ݡ�Exp:%d,Pur:%d,Kar:%d",me->query("name"),getuid(me),me->query("combat_exp"),me->query("pur"),me->query("kar")),this_object() );
	}
	else command("sigh");
	return 1;
}
///wei ����

string ask_fight()
{
	object ob = this_player();
	int i = random(5);
	if(!environment(ob)->query("no_fight") || !ob->query_temp("quest/baibian")) return 0;
	if(ob->query_temp("quest/baibian_ok")) return 0;
	while(i--)
		random_move();
	return 0;
}

void kill_ob(object ob)
{
        if(!ob) return;
        if(ob->query("quest/wxbjiebai"))
        {
        	tell_object(ob,"�����Ǹ���ݹ����ӵ�Ŷ��\n");
        	ob->remove_killer(this_object());
        	remove_killer(ob);
        	return;
        }
        if(ob->query_temp("quest/baibian_ok"))
        {
        	tell_object(ob,"�����Ȱѻ�˵����ɡ�\n");
        	ob->remove_killer(this_object());
        	remove_killer(ob);
        	return;
        }
        if(ob->query_temp("quest/baibian")) switch(ob->query_temp("quest/baibian"))
        {
        	case 1:
        	case 2:
        	case 3:
        		command("!!!");
        		command("baibian");
        		ob->add_temp("quest/baibian",1);
        		return;
        	case 4:
        	case 5:
        	case 6:
        		command("dao");
        		command("say �����㣡");
        		command("baibian");
        		ob->add_temp("quest/baibian",1);
        		return;
        	case 7:
        	case 8:
        	case 9:
        		command("faint2");
        		command("say �Ҹ����ֻ���е�С���ڣ��αء�����");
        		command("baibian");
        		ob->add_temp("quest/baibian",1);
        		return;
        	default:
			ob->remove_killer(this_object());
        		remove_killer(ob);
			ob->set_temp("quest/baibian_ok",1);
			message_vision("$N�ۼ���·���ӣ��������Ǵӻ����ͳ�һ���"HIG"��Ʊ"NOR"���˿�����\n$nһ�㹥�ƾͻ���������\n",this_object(),ob);
			command("say ��ʵ�Ҹ���̵Ĺ���Ҳûʲô��ֻ�Ǻ����ڹ���ʹ����е��벻���ס�");
			command("say �������ˣ������Ź��ң��Ҵ��㡾���аٱ䡿��Σ�");
			tell_object(ob,HIY"��Ը���ӦΤС��������ô(yes)��\n"NOR);
			return;
        }
        ob->remove_killer(this_object());
        remove_killer(ob);
        command("swear");
}

void unconcious()
{
        remove_all_killer();
        remove_all_enemy();
        say("ΤС�����һ��: ��ѽ!������\n");
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

//����ϵͳ

void start_weapon()
{       
        remove_call_out("check_time");
        call_out("check_time",5);       
}

void check_time()
{
        if (!this_object()) return;
        
        if ( query("born_weapon_time") && query("born_weapon_time") > time() ) 
        {
        call_out("check_time",5);
        return;
        }
        
        born_weapon();                  
}
void born_weapon()
{       
        int i;
        mapping *weapons;
        string name;
        int number;     
        
        weapons = allocate(WEAPON_TOTAL);
        delete("vendor_goods");
                
        i = WEAPON_LESS + random(WEAPON_TOTAL-WEAPON_LESS + 1); 
        while(i--){
                name =  WEAPON_P(i);
                number = 1 + random(WEAPON_NUMBER-1);           

		call_out("born_file",random(10),i);

                weapons[i] = (["name":name,"number":number]);
                
        }
        weapons = filter_array(weapons, (: mapp :));    
        set("vendor_goods",weapons);
        set("born_weapon_time",time() + UPDATE_TIME * 3600 );                                           
        command("rumor "HIM"��˵ΤС����Τ����������õ��˺ܶ�"HIY"����"HIM"��"NOR);
        
        remove_call_out("check_time");
        call_out("check_time",10);
        return;
}
int born_file(int i)
{	
	string name;
	name =  WEAPON_P(i);         
        if (!"/adm/daemons/user_weapond"->born_file(name)) return 1;
        //message("wizard:linux", "born_file......."+i+"\n", users());
        return 1;             
}
///added for VIP
/*int do_buy(string arg){
        object me = this_player();
        
        if ( !arg) return 0;
        if ( me->query("registered") == 3 ) return ::do_buy(arg);
        
        if ( me->query("wei_buy_weapon_times") > 10 ) {
                message_vision("$n��$Nҡ��ҡͷ˵���������ˣ������ˣ�\n",me,  this_object());
                return 1;
        }
        
        if (::do_buy(arg)==1)
        {
                if (!me->query("wei_buy_weapon_times")) me->set("wei_buy_weapon_times",1);
                else me->add("wei_buy_weapon_times",1);
        }
        else
                return 0;
        
        return 1;
}
*/
int do_look(string arg)
{
        object me = this_player();
        object wq;
        mapping *mp;
        int i,j;
        string *name;
        
        name = allocate(WEAPON_TOTAL);
        
        if ( !arg) return 0;
        //if ( me->query("registered") != 3 ) return 0;
        if (!arrayp(mp = query("vendor_goods"))) return 0;
                
        mp = filter_array(mp , (: mapp :));     
        for(i=0;i<sizeof(mp);i++) name[i] = ((object)mp[i]["name"])->query("id");       
        name = filter_array(name, (: stringp :));       
        
        j = member_array(arg,name);
        if (j == -1 ) return 0;
        
        if (mp[j]["number"] <= 0 ) return 0;//�����˾Ͳ��ÿ� :)        	
        
        if (!objectp(wq = new(mp[j]["name"]))) return 0;
        
        message_vision("$N��$n˽�Ｘ�䣬$n��ϸ�������ʹӰ������ó�һ"+wq->query("unit")+wq->name()+"������$N��\n",me,  this_object());
        tell_object(me,"\n�㿪ʼ��ϸ��ĥ��"+wq->query("unit") + wq->name()+"��\n\n"+wq->query("long")+"\n");
        message_vision("$nһ���Ӵ�$N�����ù�"+wq->name()+"�����Լ��İ����\n",me,  this_object());    
        me->start_busy(1);
        destruct(wq);
        if (wq)
        command("tell linux bug bug bug");        	
        return 1;               
}