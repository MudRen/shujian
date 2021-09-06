//tangfeng@SJ

#include <ansi.h>
#include <room.h>

inherit ROOM;
#define QUESTDIR2 "quest/�����˲�/����Ӫ��ƪ/"

void create()
{
	set("short", HIW"��ʯ·"NOR);
	set("long", @LONG
�߽����ţ�ֻ����שΧǽ����ʯ��·��������һֱͨ�������̧ͷ
��ȥ������̨ͤ¥���ģ��󣬹���������լ�����ƣ�������֮ʢ��ʤ��
��̨�����ӵ������ʤ�ص���ɽ���¡�·���������������±������߸�
��һСԺ��Ժ������������
LONG);
	set("outdoors", "������");
   set("quest",1);
	set("exits", ([             
		"northup" : __DIR__"twd",
		"west" : __DIR__"yz1",
		"east" : __DIR__"yz2",
		"out" : __DIR__"gate",
	]));
	set("objects",([
		__DIR__"npc/liao-huo" : 1,
		__DIR__"npc/wuseng" : 2,
		__DIR__"npc/guest" : 1,
	]));
	setup();
  call_other("/clone/board/tianlong_b", "???");

}
void init()
{
  object me,ob,obj,room;
  me = this_player();
  ob = this_object();
  if (me->query(QUESTDIR2+"start")
     &&me->query_temp(QUESTDIR2+"jiumozhi")
     &&!me->query_temp(QUESTDIR2+"kill_dizi")
     &&!me->query(QUESTDIR2+"over")
     &&!me->query_condition("killer"))
  {
  	//����������������quest��ȡ��quest������������
    if(ob->query("busy_id"))
    {
	    if (!(room = find_object(__DIR__"road_copy")))
			room = load_object(__DIR__"road_copy");
		if(!room)
		{
			me->delete_temp("quest/�����˲�");
			me->delete_temp("quest/busy");//�����ͻ��־ȡ�� 
			//������һ���
			me->delete("quest/�����˲�/time");
			me->delete("quest/�����˲�/combat_exp");  
			tell_object(me,HIR"\n�㷢���ƺ���Щ���⣬�����ѯ����ʦ��\n");
			log_file("quest/TLBB", sprintf("%s(%s)ȱ��road_copy.c�ļ���\n", me->name(1),me->query("id")) );	
			return;
		}
		if(room
			&& ((obj=present(ob->query("busy_id"),room))|| (obj=present(ob->query("busy_id"),ob))) && obj!=me)
		{
			if(present(obj,ob)) message_vision(HIR"\n$N��$n���˵�ͷ��\n",obj,me);
			else message_vision(HIR"\nԶ����ɽ·����һ����Х��$N��Լ�����д򶷵�������ԭ����"+obj->query("family/family_name")+HIR"����"+obj->query("name")+HIR"��\n",me);
			tell_object(me,HIY"��"+obj->query("family/master_name")+HIY"���¸�ͽ"+obj->query("name")+HIY"�����������£�Ҳ����������ˡ�"NOR);
			me->delete_temp("quest/�����˲�");
			me->delete_temp("quest/busy");//�����ͻ��־ȡ�� 
			log_file("quest/TLBB", sprintf("%s(%s)��Ϊ%s(%s)��ͻ��������ʧ�ܡ�\n", me->name(1),me->query("id"),obj->name(1),obj->query("id")) );
			//������һ���
			me->delete("quest/�����˲�/time");
			me->delete("quest/�����˲�/combat_exp");  
			return;  
		}
	}
	ob->set("busy_id",me->query("id"));
	me->start_busy(1);
	remove_call_out("go");
	call_out("go", 1,me);   
  }      
}

void go(object me)
{
  object room,ob;
  ob = this_object();
  remove_call_out("go");
  if(!me) 
  {
  	ob->delete("busy_id");
  	return;
  }
  if(!present(me,this_object())) 
  {
	  tell_object(me,HIY"\n���㱣�������£�Ϊ���Ĵ����ߣ�\n"NOR);
	  tell_object(me,HIY"վλ��������ʧ�ܣ���\n"NOR);
	  me->delete_temp("quest/�����˲�");
	  me->delete_temp("quest/busy");//�����ͻ��־ȡ�� 
	  log_file("quest/TLBB", sprintf("%s(%s)������վλ���ԣ�ʧ�ܡ�\n", me->name(1),me->query("id")) );
	  me->delete(QUESTDIR2+"start");
	  ob->delete("busy_id");
	  return;
  }
  if (!(room = find_object(__DIR__"road_copy")))
        room = load_object(__DIR__"road_copy");
  if(!room)
  {
	  tell_object(me,HIY"\nԶ����ɽ·����һ����Х����Լ�����д򶷵�������\n"NOR);
	  tell_object(me,HIY"�����������޷��ҵ���ȷ�ĵص㡣����ѯ����ʦ��\n"NOR);
	  me->delete_temp("quest/�����˲�");
	  me->delete_temp("quest/busy");//�����ͻ��־ȡ�� 
      ob->delete("busy_id");
	  //������һ���
 	  me->delete("quest/�����˲�/time");
	  me->delete("quest/�����˲�/combat_exp");  
  	  log_file("quest/TLBB", sprintf("%s(%s)������ȱ��road_copy.c�ļ���\n", me->name(1),me->query("id")) );
	  return;
  }
  if(room->query("busy_id"))
  {
    tell_object(me,HIY"\nԶ����ɽ·����һ����Х����Լ�����д򶷵�������\n"NOR);
	tell_object(me,HIY"�㻹�����ĵصȴ��ɡ�\n"NOR);
    call_out("go", 5,me);   
  }
  else 
  {
  	me->move(room);
	ob->delete("busy_id");
  	log_file("quest/TLBB", sprintf("%s(%s)�����·���վ��ʼս�������飺%d��\n", me->name(1),me->query("id"), me->query("combat_exp")) );
  }
}
int valid_leave(object me, string dir)
{
		
	if ( me->query("family/family_name") != "������" 
	 && dir != "out" 
	 && me->query("shen") < 0
	 && objectp(present("liaohuo chanshi", environment(me))))
		return notify_fail("�˻���ʦ��ס�㣬˵�����������ڲ������������\n");

	if ( me->query("family/family_name") != "������" 
	 && dir != "out" 
	 && me->query("shen") < 0
	 && objectp(present("wu seng", environment(me))))
		return notify_fail("��ɮ��ס�㣬˵�����������ڲ������������\n");
	return ::valid_leave(me, dir);
}
