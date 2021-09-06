// /d/tls/npc/dlsdizi.c
//tangfeng@SJ 2004
//inherit NPC;
inherit FIGHTER;
inherit F_UNIQUE;
#include <ansi.h>

#define QUESTDIR2 "quest/�����˲�/����Ӫ��ƪ/"

int power_condition(object me, object ob,int p);
int pfm();
int do_kill(object ob);
int checking(object me, object ob);
void create()
{
	mapping name;
	int sex = random(3);
  name = RNAME_D->get_random_name(random(3));
	set_name(name["name"], name["id"]);
	set_name(query("name"), ({ query("id"),"dls dizi"}));
  set("title", HIY"�����µ���"NOR);
	set("gender", (sex?"����":"Ů��"));
	set("long", "�����¸��֡�\n");
	set("str", 25);
	set("dex", 25);
	set("con", 25);
	set("int", 25);
	set("per", 25);
	set("shen_type", -1);
  create_family("������", 10, "����");
  set_skill("huanxi-chan", 200);
  set_skill("literate", 150);
  set_skill("force", 200);
  set_skill("longxiang-boruo", 200);
  set_skill("dodge", 290);
  set_skill("blade", 290);
  set_skill("xuedao-jing", 290);
	set_skill("poison", 100);
  set_skill("yuxue-dunxing", 290);
  set_skill("strike", 290);
  set_skill("huoyan-dao", 300);
  set_skill("parry", 290 );
  set_skill("hammer",290);
  set_skill("xiangfu-lun",290);
  set_skill("wuxing-zhen",290);
  map_skill("force", "longxiang-boruo");
  map_skill("dodge", "yuxue-dunxing");
  map_skill("strike", "huoyan-dao");
  map_skill("blade", "xuedao-jing");
  map_skill("hammer","xiangfu-lun");
  map_skill("parry", "huoyan-dao");
  prepare_skill("strike","huoyan-dao");
  
        set("chat_chance_combat", 30);
		set("chat_msg_combat", ({ 
			(: pfm :),
		}));     

	set("combat_exp", 2000000);
	set("max_qi", 30000);
	set("max_jing", 8000);
	set("max_neili", 8000);
	set("eff_jingli",8000);
	set("qi",30000);
	set("jing",8000);
	set("jingli",8000);
	set("neili", 16000);

  setup();  
	if (!random(3))
	   add_money("gold", random(5)+1);
  carry_object("/d/xueshan/npc/obj/longxiang-jiasha")->wear();
}
int pfm()
{
      object me,weapon;
      int i;
      me = this_object();
      weapon = me->query_temp("weapon");
      if(me->is_busy()) return 0;  
      if(objectp(weapon)) weapon->unequip();  
      if(me->query("type")) i=me->query("type");
      else i=random(4);
     
      switch(i)
      {
      	case 1:
      	      weapon=present("blade",me);
			  if (!(objectp(weapon)))  carry_object(BINGQI_D("blade"))->wield();
			  else weapon->wield();
			  me->map_skill("parry", "xuedao-jing");
			  me->map_skill("blade", "xuedao-jing");
			  if(random(4)==1) command("perform shendao");
			  break;
      	case 2:
      	      weapon=present("fa lun",me);
      	      if (!(objectp(weapon)))  carry_object(BINGQI_D("falun"))->wield();
	            else weapon->wield();
	            me->map_skill("parry", "xiangfu-lun");
	            me->map_skill("hammer", "xiangfu-lun");
                    if(!random(3)) command("perform wushuai");
      	      break;
      	case 3:
	            me->map_skill("parry", "huoyan-dao");
	            me->map_skill("strike", "huoyan-dao");
                                if(!random(4)) command("yun longxiang");
				else if(random(2)) command("perform ran");
				else command("perform daoqi");
				break;
      	default:
	            me->map_skill("parry", "huoyan-dao");
	            me->map_skill("strike", "huoyan-dao");
                                if(!random(4)) command("yun longxiang");
                    else if(random(2)) command("perform ran");
                    else command("perform daoqi");
      	      break;      	      
      }
        return 1;
}

void init()
{
        object me, ob;       
        ::init();

        ob = this_object();
        if(!ob->query("kill_id")) return;
	  	  me=find_player(ob->query("kill_id"));
	  	  if(!me) return;
	  	  if(environment(me)!=environment(ob)) return;
	      if(ob->query("setok")) return;
 		    ob->set("setok",1);
        if(ob->query("type")==1) message_vision(HIG"$N���˵�ͷ����������������������£����ǸϿ��ȥ�ɣ���\n"NOR,ob);
        if(ob->query("type")==2) message_vision(HIG"$N��Цһ��������ν�Ĵ�����ߵ���ѧʤ�أ�Ҳ������ˣ���\n"NOR,ob,me);
        if(ob->query("type")==3) message_vision(HIY"$NͻȻ����ؿ���$nһ�ۼ���������С�ġ����ˡ����󣡡�\n"NOR,ob,me);
        power_condition(me, ob,100+random(100));
			  remove_call_out("zhen");
                          call_out("zhen",5,ob);
			  remove_call_out("dest");
			  call_out("dest", 600,ob);
			  remove_call_out("do_kill");
                          call_out("do_kill",8, me);
}
void zhen(object ob) 
{
   if( !ob ) return;                   
   command("lineup with dls dizi 1");
   command("lineup with dls dizi 2");
   command("lineup with dls dizi 3");
   command("lineup with dls dizi 4");
   command("lineup with dls dizi 5");
   command("lineup form wuxing-zhen");   
   command("lineup with dls dizi 1");
   command("lineup with dls dizi 2");
   command("lineup with dls dizi 3");
   command("lineup with dls dizi 4");
   command("lineup with dls dizi 5");
   command("yun longxiang");
   command("yun shield");
   call_out("zhen",1,ob);
}
int do_kill(object me)
{
	object ob = this_object();
	if(!me) return 0;
  if(!random(3)) message_vision(HIG"����һ����Ӱ���˳�����$N��ݺݵص�����"+me->name()+"�����"+RANK_D->query_rude(ob)+ "������������\n"NOR,ob);
  else if(random(2)) message_vision(HIY"\n$N�����شӽ��������˳�������Цһ��������֪��ߵغ񣬾�Ȼ���谭"+RANK_D->query_self_rude(ob) +"��ȥ·��\n"NOR,ob);
  else message_vision(HIB"\n$N�������������һ���ϣ�"+me->name()+"�����书�ٸߣ�Ҳ���������Ǵ����µĶ��֣���\n"NOR,ob);
	remove_call_out("checking");
	call_out("checking", 2, me, ob);
	::do_kill(me);
}

//��飬quest���̲���������
int checking(object me, object ob)
{
	int ret =  ::checking(me,ob);
	//me=this_palyer(),ob=this_object()
	if(!ret) return 0;
	remove_call_out("checking");
	call_out("checking", 1, me, ob);
  if(!living(me) && living(ob) && ob->query("jing")>0 && ob->query("jingli")>0 && ob->query("qi")>0  ){
		remove_call_out("checking");
		me->delete(QUESTDIR2+"start");
		me->delete_temp("quest/�����˲�");
		me->delete_temp("quest/busy");//�����ͻ��־ȡ��
		me->set("qi",100);													
		me->set("quest/�����˲�/time",time());
		me->set("quest/�����˲�/combat_exp",me->query("combat_exp"));
		log_file("quest/TLBB", sprintf("%s��¼��%s(%s)����Ӫ��ƪʧ�ܡ�����%d��\n", ob->name(1),me->name(1),me->query("id"), me->query("combat_exp")) );
		me->set("jing",100);
		me->set("jingli",100);
		tell_room(environment(ob), HIB"\n"+ob->name()+"����һ�����������������£�ת��������Ͳ����ˡ�\n"NOR);
		destruct(ob);
		return 1;
	}
        if(!me || environment(ob)!= environment(me)||me->query("eff_qi")<me->query("max_qi")/10||me->query("qi")<me->query("max_qi")/20){
		remove_call_out("checking");
		remove_call_out("do_lost");
        call_out("do_lost",0);
		return 1;
	}
   if(!me->is_fighting(ob))  call_out("do_kill",1,me);
}
void do_lost()
{
	object me,ob;
	ob = this_object();
	me = find_player(ob->query("kill_id"));
	if(!me) return;
	me->delete(QUESTDIR2+"start");
	me->delete_temp("quest/�����˲�");
	me->delete_temp("quest/busy");//�����ͻ��־ȡ��
	me->set("quest/�����˲�/time",time());
	me->set("quest/�����˲�/combat_exp",me->query("combat_exp"));
	log_file("quest/TLBB", sprintf("%s��¼��%s(%s)����Ӫ��ƪʧ�ܡ�����%d��\n", ob->name(1),me->name(1),me->query("id"), me->query("combat_exp")) );
    if(random(2)) tell_room(environment(ob), HIB"\n"+ob->name()+"����һ������"+me->name()+"�Ѿ��������ˣ���������һ������˵�꣬"+ob->name()+"�������������¡�\n"NOR);
	else tell_room(environment(ob), HIB"\n"+ob->name()+"����˵��������ֵ����"+me->name()+"�����˷�̫��ʱ�䣬���Ǵ���Ϊ�أ���������һ�������ǻ��ǿ��߰ɡ���˵�꼲�����������¡�\n"NOR);
	destruct(ob);
}

void dest(object ob)
{
  if(!ob) return;
  tell_room(environment(ob), HIR+"\n"+ob->name()+"����һ���������һ��Ҵ������ˡ�\n"NOR);
	destruct(ob);
}
void die()
{
	object me,ob=this_object();
	
	if(ob->query("kill_id") )
	{
		if((me=present(ob->query("kill_id"),environment(ob))) 
			&& me->query_temp(QUESTDIR2+"jiumozhi"))
		{           
			if(!me->query_temp(QUESTDIR2+"kill_dizi"))
			{
				me->add_temp(QUESTDIR2+"kill_dizi_",1);
				if(me->query_temp(QUESTDIR2+"kill_dizi_")==2)
				{
					me->set_temp(QUESTDIR2+"kill_dizi",1);
					me->delete_temp(QUESTDIR2+"kill_dizi_");
				}
			}
		}
    else command("poor");
	}
	::die();
}
void unconcious()
{
  die();
}
int power_condition(object me,object ob,int p)
{
	  int i;
	  i=me->query("max_pot");
	  if(p<150) p=150;
	  if(i<p) i=p;
	  i=i-100;	  
    ob->set_skill("huanxi-chan", i+random(50)-25);
    ob->set_skill("literate", i+random(50)-25);
    ob->set_skill("force", i+random(50)-25);
    ob->set_skill("longxiang-boruo", i+random(50)-25);
    ob->set_skill("dodge", i+random(50)-25);
    ob->set_skill("blade", i+random(50)-25);
    ob->set_skill("xuedao-jing", i+random(50)-25);
	  ob->set_skill("poison", 200);
    ob->set_skill("yuxue-dunxing", i+random(50)-25);
    ob->set_skill("strike", i+random(50)-25);
    ob->set_skill("huoyan-dao", i+random(50)-25);
    ob->set_skill("parry", i+random(50)-25);
    ob->set_skill("hammer",i+random(50)-25);
    ob->set_skill("xiangfu-lun",i+random(50)-25);
	  i=me->query("combat_exp");
	  ob->set("combat_exp",i+random(i/10)-random(i/10));
	  i=me->query("neili");	  
	  if(i<12000) i=12000;
	  ob->set("neili", i);	  
	  i=me->query("max_neili");	  
	  if(i<6000) i=6000;
	  ob->set("max_neili", i);	  
  	i=me->query("max_qi");	  
          ob->set("max_qi", i); 
	  ob->set("jiali", 20+random(80));  
	  ob->set("max_jing",me->query("max_jing"));
	  ob->set("max_jingli",me->query("max_jingli"));
	  ob->set("jingli",me->query("jingli"));
	  ob->set("eff_jing",me->query("max_jing"));
	  ob->set("jing",me->query("max_jing"));  
 	  ob->set("eff_qi", ob->query("max_qi"));	
 	  ob->set("qi", ob->query("max_qi"));	
 	  ob->set("jiali",20+random(100));
    return 1;
}
