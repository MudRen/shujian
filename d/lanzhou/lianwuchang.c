//tangfeng@SJ 2004
//������̨�Ĺ���
//��쳺����˷����ĳ���

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
������һ���ƾɵ����䳡����ǧ��Ĳ�̤��ʹ����Щʯ����ͬ���Ӱ�ƽ
���⻬�����������һ�������(paizi)��
LONG
	);
  set("no_death", 1);
  set("no_get_from", 1); 
  set("no_sleep_room", 1);

  set("item_desc", ([             
  "paizi" : "\n׼�����˺���� OK �����Ҫ������������� LEAVE ��\n\n",
  ]));
  setup();
}
void init()
{
	object me,ob;
	me = this_player();
	message_vision("$N����ææ���߽������䳡��\n", me);
	if (!userp(me)) return;
  add_action("do_leave", "leave");
	if (!me->query_temp("quest/ѩɽ�ɺ�/�书/fight_id")) return;
	if (!(ob=present(me->query_temp("quest/ѩɽ�ɺ�/�书/fight_id"),this_object()))) return;
	message_vision(HIG"\n$N��$n���˵�ͷ��\n"NOR,ob,me);
	this_object()->set_temp("biwu",1);
	add_action("do_ok", "ok");
	add_action("do_action", ({"dazuo", "tuna", "lian", "learn", "du", "steal", "hit",
                                  "kill", "fight", "study", "practice", "exercise", "halt", "ask","whisper",
	                          "quit", "save", "throw", "rumor", "tell", "mm", "reply",
	                          "chat", "rumor", "party", "shout", "suicide", "yield"}));
}

int do_action(string arg)
{
	if(!wizardp(this_player())){
		write("���䳡��ֻ�ܱ��䣬�벻Ҫ������ص��£�\n");
		return 1;
	}
	else return 0;
}

int do_ok()
{
	object ob, me = this_player();
	if (!me->query_temp("quest/ѩɽ�ɺ�/�书/fight_id")) return 0;
	if (!(ob=present(me->query_temp("quest/ѩɽ�ɺ�/�书/fight_id"),this_object()))) return 0;
	if (!ob->query_temp("biwu")) return 0;
        if (this_object()->query_temp("biwu")==2) return 0;
        if (!this_object()->query_temp("biwu")) return 0;
	this_object()->set_temp("biwu",2);
	message_vision(HIR"\n$N���˸��ϣ�"+RANK_D->query_self(ob)+"�Ѿ�׼�����ˣ�Ը�����κ���ս��\n"NOR, ob);
	message_vision(HIR"\n$N���˸��ϣ�"+RANK_D->query_self(me)+"�Ѿ�׼�����ˣ�Ը�����κ���ս��\n"NOR, me);
  me->kill_ob(ob);
  ob->kill_ob(me);
  remove_call_out("check");
  call_out("check",1,me);
	return 1;
}
void check(object me)
{
	object room,obj,ob;
	if(!me || !living(me)||!present(me,this_object())||me->query("qi")<=1||me->query("jing")<=1||!me->query_temp("quest/ѩɽ�ɺ�/�书/fight_id"))  
	{
		remove_call_out("check");
		
		//npc����
		if((ob=present("hu fei",this_object())))
		{
	  	 message_vision(HIW"\n$Nһ���߰�����̬����Ȼû�˸�����ս������"+RANK_D->query_self(ob)+"���������޵��ˣ�\n\n"NOR, ob);
		 ob->remove_all_killer();  
	  	 ob->delete_temp("biwu");
	  	 ob->delete_temp("quest/try_fight_id");
			 if (!(room = find_object("/d/huanghe/fendi")))
            room = load_object("/d/huanghe/fendi");
       if( !room ) destruct(ob);
       else
       {
       	 if(!present("hu fei",room))
       	 {
       	 	message_vision(HIY"$N����ææ���뿪�����䳡��\n"NOR, ob);
       	 	ob->move(room);
			ob->remove_all_killer();  
       	 	message_vision("$N����ææ��������"+environment(ob)->query("short")+"��\n", ob);
       	 }
  	     else destruct(ob);
       }
    }
		if((ob=present("miao renfeng",this_object())))
		{
	  	 message_vision(HIW"\n$Nһ���߰�����̬����Ȼû�˸�����ս������"+RANK_D->query_self(ob)+"���������޵��ˣ�\n\n"NOR, ob);
		 ob->remove_all_killer();  
	  	 ob->delete_temp("biwu");
	  	 ob->delete_temp("quest/try_fight_id");
			 if (!(room = find_object("/d/lanzhou/zhenting")))
            room = load_object("/d/lanzhou/zhenting");
       if( !room ) destruct(ob);
       else
       {
       	 if(!present("miao renfeng",room)) 
       	 {
       	 	message_vision(HIC"$N����ææ���뿪�����䳡��\n"NOR, ob);
       	 	ob->move(room);
			ob->remove_all_killer();  
       	 	message_vision("$N����ææ��������"+environment(ob)->query("short")+"��\n", ob);
       	 }
  	     else destruct(ob);
       }
    }
    //ʧ�ܺ��ȥ��
    if(userp(me))
    { 
    	if(present(me,this_object()))
    	{
       	me->remove_all_killer();
		    me->revive();
    		me->reincarnate();
			
	  	  message_vision(HIW"\nͻȻһ�����������$N��$N�ľ�����Ȼȫ���ָ��ˣ�\n"NOR, me);
     	 	message_vision(HIY"$N����ææ���뿪�����䳡��\n"NOR, me);
        if(me->query_temp("quest/ѩɽ�ɺ�/�书/fight_id")=="miao renfeng") me->move("/d/lanzhou/zhenting");
        else me->move("/d/huanghe/fendi");
    		tell_object(me,HIR"\n����ʧ�ܣ��´�Ŭ����\n"NOR);
  log_file("quest/FEIHU", sprintf("%s(%s) ����ʧ�ܡ����飺%d��\n", me->name(1),me->query("id"),me->query("combat_exp")) );
    		message_vision("$N����ææ��������"+environment(me)->query("short")+"��\n", me);
    	}
    	else	tell_object(me,HIR"\n������˲�ר�ģ����ܲ�ʧ�ܣ��´�Ŭ���ɣ�\n"NOR);
    }
   	me->delete_temp("quest/ѩɽ�ɺ�/�书/fight_id");
    this_object()->delete_temp("biwu");
	  return;
	}
	if (!(ob=present(me->query_temp("quest/ѩɽ�ɺ�/�书/fight_id"),this_object())))
	{
		  remove_call_out("check");
      me->add("combat_exp",500+me->query_skill("force")*3/2);
      tell_object(me,HIC"\n����һ���භ���㷢���Լ����书���м���������"+(500+me->query_skill("force")*3/2)+"�㾭�顣\n"NOR);
 
            tell_room(environment(me),HIC"\n"+me->query("name")+"����һ���򶷣��ƺ��书���г�����\n"NOR, ({ me }));
      me->set("quest/ѩɽ�ɺ�/�书/time",time());
	  me->set("quest/ѩɽ�ɺ�/�书/fight_exp",me->query("combat_exp"));
      me->remove_all_killer();  
	  me->revive();
    	me->reincarnate();
	  	message_vision(HIW"\nͻȻһ�����������$N��$N�ľ�����Ȼȫ���ָ��ˣ�\n\n"NOR, me);
     	message_vision(HIR"$N����ææ���뿪�����䳡��\n"NOR, me);
	  	if(me->query_temp("quest/ѩɽ�ɺ�/�书/fight_id")=="hu fei") 
	  	{
			if(!me->query("quest/ѩɽ�ɺ�/�书/win_hu")) me->set("quest/ѩɽ�ɺ�/�书/win_hu",1);
			else me->add("quest/ѩɽ�ɺ�/�书/win_hu",1);
			log_file("quest/FEIHU", sprintf("%s(%s) �ͺ�쳽�����ʤ����þ��齱����%d�����飺%d��\n", me->name(1),me->query("id"),(500+me->query_skill("force")*3/2),me->query("combat_exp")) );
	  		if (!(room = find_object("/d/huanghe/fendi")))
                   room = load_object("/d/huanghe/fendi");
        obj=new("/d/huanghe/npc/hu-fei");
        if(!present("hu fei",room)) obj->move(room);
        me->move(room);
      }
	  	else if(me->query_temp("quest/ѩɽ�ɺ�/�书/fight_id")=="miao renfeng") 
	  	{
			if(!me->query("quest/ѩɽ�ɺ�/�书/win_miao")) me->set("quest/ѩɽ�ɺ�/�书/win_miao",1);
			else me->add("quest/ѩɽ�ɺ�/�书/win_miao",1);
  log_file("quest/FEIHU", sprintf("%s(%s) �����˷������ʤ����þ��齱����%d�����飺%d��\n", me->name(1),me->query("id"),(500+me->query_skill("force")*3/2),me->query("combat_exp")) );
	  		if (!(room = find_object("/d/lanzhou/zhenting")))
                   room = load_object("/d/lanzhou/zhenting");
        obj=new("/d/lanzhou/npc/miaorenfeng");
        if(!present("miao renfeng",room)) obj->move(room);
        me->move(room);
      }
      else me->move("/d/xiangyang/damen");
    	message_vision("$N����ææ��������"+environment(me)->query("short")+"��\n", me);
    	me->delete_temp("quest/ѩɽ�ɺ�/�书/fight_id");
      this_object()->delete_temp("biwu");
    	return;
	}
  call_out("check",1,me);
}

int do_leave()
{
	object ob,room,me = this_player();
  if(this_object()->query_temp("biwu")==2) 
  {
  	tell_object(me,HIR"\n�����ڱ���֮�У��޷��˳�������\n"NOR);
  	return 1;
  }
  me->set("quest/ѩɽ�ɺ�/�书/time",time());
  me->remove_all_killer();   	
	me->reincarnate();
	message_vision(HIW"\n$N��̾��һ�������˳����䳡��\n\n"NOR, me);
	remove_call_out("check");
	if((ob=present("hu fei",this_object())))
	{
	  	 message_vision(HIW"\n$Nһ���߰�����̬����Ȼû�˸�����ս������"+RANK_D->query_self(ob)+"���������޵��ˣ�\n\n"NOR, ob);
		 ob->remove_all_killer();  
	  	 ob->delete_temp("biwu");
	  	 ob->delete_temp("quest/try_fight_id");
			 if (!(room = find_object("/d/huanghe/fendi")))
            room = load_object("/d/huanghe/fendi");
       if( !room ) destruct(ob);
       else
       {
       	 if(!present("hu fei",room)) 
       	 {
       	 	message_vision("$N����ææ���뿪�����䳡��\n", ob);
       	 	ob->move(room);
			ob->remove_all_killer();  
       	 	message_vision("$N����ææ��������"+environment(ob)->query("short")+"��\n", ob);
       	 }
  	     else destruct(ob);
       }
  }
  if((ob=present("miao renfeng",this_object())))
	{
	  	 message_vision(HIW"\n$Nһ���߰�����̬����Ȼû�˸�����ս������"+RANK_D->query_self(ob)+"���������޵��ˣ�\n\n"NOR, ob);
		 ob->remove_all_killer();  
	  	 ob->delete_temp("biwu");
	  	 ob->delete_temp("quest/try_fight_id");
			 if (!(room = find_object("/d/lanzhou/zhenting")))
            room = load_object("/d/lanzhou/zhenting");
       if( !room ) destruct(ob);
       else
       {
       	 if(!present("miao renfeng",room)) 
       	 {
       	 	message_vision("$N����ææ���뿪�����䳡��\n", ob);
       	 	ob->move(room);
			ob->remove_all_killer();  
       	 	message_vision("$N����ææ��������"+environment(ob)->query("short")+"��\n", ob);
       	 }
  	     else destruct(ob);
       }
  }
 	message_vision(HIY"$N����ææ���뿪�����䳡��\n"NOR, me);
  if(me->query_temp("quest/ѩɽ�ɺ�/�书/fight_id")=="miao renfeng") me->move("/d/lanzhou/zhenting");
  else me->move("/d/huanghe/fendi");
  me->delete_temp("quest/ѩɽ�ɺ�/�书/fight_id");
	message_vision("$N����ææ��������"+environment(me)->query("short")+"��\n", me);
   log_file("quest/FEIHU", sprintf("%s(%s) ��ֹ���������飺%d��\n", me->name(1),me->query("id"),me->query("combat_exp")) );
  this_object()->delete_temp("biwu");
	return 1;
}
