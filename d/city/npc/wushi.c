//���±��䳡��ȭ��
//Created by campsun 2003.09.23
#include <ansi.h>

inherit NPC;


#include <skills_pfm.h>;
#include <r_name.h>


string *nick_first=({
HIB"�Ϻ�"NOR,HIY"ƽԭ"NOR,HIW"�ɶ�"NOR,HIG"����"NOR,RED"ƽ��"NOR,WHT"����"NOR,
HIB"����"NOR,HIW"Ʈѩ"NOR,YEL"���"NOR,HIY"����"NOR,MAG"���"NOR,HIR"Ϧ��"NOR,
HIY"����"NOR,});

string *nick_second=({
HIM"��"NOR,CYN"��"NOR,RED"��"NOR,WHT"ǹ"NOR,HIB"��"NOR,YEL"��"NOR,HIR"��"NOR,
CYN"��"NOR,HIB"��"NOR,HIY"��"NOR,HIR"����"NOR,HIG"��"NOR,WHT"��"NOR,HIB"��"NOR,
});


string create_nick()
{
	string nick1,nick2;
	nick1=nick_first[random(sizeof(nick_first))];
	nick2=nick_second[random(sizeof(nick_second))];
	if(random(5)>3)
		return nick1+"һ"+nick2;
	else
		return nick1+nick2;
}


void set_random_gift();

void create ()
{
		set_name("������",({"wuming shi"}));

       	set("shen_type", 1);
       	set("age", random(80)+10);
        set("attitude","heroism");
       	
		set("tag","red");
		set("max_jing",6000);
		set("max_qi",6000);
        set_random_gift();
        set("no_get", "����������"+query("name")+"��̨��ק��������ϧ�����˺ô�һ�ء�\n");
        set("cloned",0);
  	
        setup();
}    
void set_random_gift()
{
	int i = 10, j;
	int tmpstr, tmpint, tmpcon, tmpdex;
	int select =0;
	
	tmpstr = tmpint = tmpcon = tmpdex = 10;

	i = 50 - i;
	while (i--) {
		j = random(4);
		if (j == select - 1) i++;
		else switch (j) {
			case 0: if (tmpstr < 30) tmpstr++;
				else i++;
				break;
			case 1: if (tmpint < 30) tmpint++;
				else i++;
				break;
			case 2: if (tmpcon < 30) tmpcon++;
				else i++;
				break;
			case 3: if (tmpdex < 30) tmpdex++;
				else i++;
		}
	}
	set("str",tmpstr);
	set("int",tmpint);
	set("con",tmpcon);
	set("dex",tmpdex);

    set("kar", 10+random(21));
    set("per", 10+random(21));
	set("pur", 10+random(21));
}
void init()
{
	object me;
	object room;
	string npc_party;
	string good_skills;
	string title;
	int exp;
	int level;
	int i;
	string nickname = create_nick();

    	::init();
	me=this_object();
	
	i = 30 + random(30);


	if(!me->query("cloned") && objectp(room=environment(me)))
	{
		exp=room->query("base_exp");
		if(me->query("tag")=="red")
		npc_party=room->query("red_party");
		if(me->query("tag")=="black")
		npc_party=room->query("black_party");
			me->set("shen",0);
		if (npc_party=="sl" || npc_party=="wd" || npc_party=="tls" || npc_party=="hs" || npc_party=="em" || npc_party=="gb")
			me->set("shen",exp);
		if (npc_party=="ss" || npc_party=="dls" || npc_party=="kl" || npc_party=="sld" || npc_party=="xx")
			me->set("shen",-exp);
	
		for (level = to_int(pow(10.0 * exp, 0.3333333));to_int(level*level/10.0*level)<=exp;level++);
		

		copy_menpai(({npc_party}),room->query("level"),room->query("use_weapon"),i);					//����npc�������书��							
	
		get_npc_name();																		//���������趨npc������
		
		if(me->query("family/family_name")=="�������ܵĴ���")
			set("gender","����");
		
		set("nickname",nickname);
	
		copy_state();																		//�������ɸ���npc ��һЩ״̬
		
		if(me->query("tag")=="red")
		{
			title=HIR"�췽 ";
			set_name(query("name"),({query("id"),"red"}) );
			set("pfm_rate",i);
		}
		if(me->query("tag")=="black")
		{
			title=HIB"�ڷ� ";
			set_name(query("name"),({query("id"),"black"}));
			set("pfm_rate",i);
		}	
		
		if(query("shen")>0)
			title=title+""HIW+query("family/family_name");
		else
			if(query("shen")<0)
				title=title+""HIC+query("family/family_name");
			else
				title=title+""HIY+query("family/family_name");
		set("title",title+""NOR);
		
		
		set("max_neili",(query_skill("force")-query_temp("apply/force"))*8 + exp/1000 + query_temp("apply/neili"));
		set("max_jingli",query_skill("force")*8);
		
		set("neili",query("max_neili"));
		set("jingli",query("max_jingli"));
		set("eff_jingli",query("max_jingli"));
		set("qi",query("max_qi"));
		set("eff_qi",query("max_qi"));
		set("jing",query("max_jing"));
		set("eff_jing",query("max_jing"));
		
		
		set_skills_level(level);
		if (!room->query("use_weapon"))
			if (me->query("f_skill2")) 
				good_skills=to_chinese(me->query("f_skill"))+"��"+to_chinese(me->query("f_skill2"));
			else	
				good_skills=to_chinese(me->query("f_skill"));
		else
		{
			good_skills=to_chinese(me->query("f_w_skill"));
			call_out("check_weapon",4);																		//���npc������״̬
			
		}
		set("good_skills",good_skills);
		
        	set("long",
       	 	"����һ�ۿ���ȥ����"HIW+me->query("family/family_name")+NOR"�ĸ��֡�\n"
       	 	"���������ǣ�"HIC+good_skills+NOR"��\n"
       	 	"���ľ���Լ��"+room->query("base_exp")/1000000+"M���ҡ�\n"
       	 	);
       	 	me->set("jiali",room->query("base_jiali")*20);
       		me->set("combat_exp",room->query("base_exp"));
 		me->set_skill("literate",me->query("int")*10); 	 											//full literate

		me->set("cloned",1);
		if (random(1000)==47) me->set("double_attack",1);
		 setup();
	};

}


void check_weapon()
{
	object w;
	object me=this_object();
	object obweapon=me->query_temp("weapon");
	string weapon,msg;
		
	weapon=me->query("u_weapon");
	msg="";
	
	remove_call_out("check_weapon");
	if(random(100)<3 && objectp(obweapon) && !me->is_busy() && !me->is_exert() && !me->is_perform() && me->is_fighting())
	{
		msg+="ͻȻ�������������,����ʹ��";
		if (me->query("f_skill2")) 
			msg+=to_chinese(me->query("f_skill"))+"��"+to_chinese(me->query("f_skill2"));
		else	
			msg+=to_chinese(me->query("f_skill"));
		msg+=HIC"�ľ���";	
		message_vision(HIC"$N"+msg+NOR"��\n",me);
		obweapon->unequip();
        me->map_skill("parry",me->query("nw_parry"));									//����������������pfm
        me->set("chat_msg_combat", query("u_f_pfm") + query("u_pfm"));
        call_out("check_weapon",30);
		return;		
	}
    if( stringp(weapon) && weapon!="" && weapon!="null" && !me->query_temp("weapon") && !me->is_busy() && !me->is_perform() ) {
    	if(random(10)>7)																	//�ٴΰ�������������
    	{
        	me->map_skill("parry",me->query("w_parry"));
        	w = new(BINGQI_D(weapon));
        	w->move(me);
        	w->wield(me);
        	msg+=w->query("unit")+w->query("name");
        	message_vision(WHT"$Nһ����Խ����̨�ߵı������ԣ�˳�ֳ����"+msg+NOR"��\n",me);
        	me->set("chat_msg_combat", query("u_f_pfm") + query("u_w_pfm"));
        	call_out("check_weapon",4);
        }
        else
        {
        	msg+="�ۼ����������Լ�����ʮ��֮ң��˫��ʹ��"HIW;
			if (me->query("f_skill2")) 
				msg+=to_chinese(me->query("f_skill"))+"��"+to_chinese(me->query("f_skill2"));
			else	
				msg+=to_chinese(me->query("f_skill"));
			msg+=HIC"�ľ���";
			message_vision(HIC"$N"+msg+NOR"��\n",me);
        	me->map_skill("parry",me->query("nw_parry"));									//����������������pfm
        	me->set("chat_msg_combat", query("u_f_pfm") + query("u_pfm"));
        	call_out("check_weapon",60);
        	return;
        }
        
      }
      call_out("check_weapon",4); 
	
}

void die()
{
	object ob,me;
	object room;
	me=this_object();
	
	if(objectp(ob = query_temp("last_damage_from")) && objectp( room=environment(me)))
	{
		if(ob->query("tag")=="black")
			room->set("winner","black");
		else 
			room->set("winner","red");
		room->get_bound();
	    ::die();
    }	
	
}

