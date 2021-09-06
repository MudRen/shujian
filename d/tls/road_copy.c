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
		__DIR__"npc/wuseng" : 2,
		__DIR__"npc/guest" : 1,
	]));
	setup();
}
void init()
{
  object me;
  me = this_player();
  if (me->query(QUESTDIR2+"start")
     &&me->query_temp(QUESTDIR2+"jiumozhi")
     &&!me->query_temp(QUESTDIR2+"kill_dizi")
     &&!me->query(QUESTDIR2+"over")
     &&!this_object()->query("busy_id"))
  {
     me->start_busy(1);
     message_vision(HIR"\n�������˶�ϡ�ٵ������½��ո��Ե��ޱ���ɱ��$N����¶�����ĵ���ɫ��\n",me);
     tell_object(me,HIB"�������ⳡս�����Ƿ�ͬС�ɣ������ʯ·������ͨ�����õıؾ�֮·��\n"NOR); 
     this_object()->set("busy_id",me->query("id"));
     remove_call_out("killme");
     call_out("killme", 20, me);   
  }      
}
void killme(object me)
{
	object obj;
  if(!me) return;
  if(!present(me,this_object())) 
  {
    tell_object(me,HIG"�㾹Ȼ���ڰ�ʯ·��Ҳ�����������ѣ��ӹ�һ�١�ֻ����Ľ�����������½���\n"NOR); 
    me->delete_temp("quest/�����˲�");
	me->delete_temp("quest/busy");//�����ͻ��־ȡ�� 
    me->delete(QUESTDIR2+"start");
    me->add("mana",-random(300)-200);
    if(me->query("mana")<0) me->set("mana",0);
    this_object()->delete("busy_id");
	log_file("quest/TLBB", sprintf("%s(%s)û��һֱ���ڰ�ʯ·��ʧ�ܡ�\n", me->name(1),me->query("id")) );
  	return;
  }
  if(me->query_condition("killer"))
  {
    tell_object(me,HIG"���ʱ���ڣ��㾹Ȼ��ר�Ŀ��ذ�ʯ·�������ٷ������ˣ�������Ľ�����������½���\n"NOR); 
    me->delete_temp("quest/�����˲�");
    me->delete(QUESTDIR2+"start");
	me->delete_temp("quest/busy");//�����ͻ��־ȡ�� 
    me->add("mana",-random(300)-200);
    if(me->query("mana")<0) me->set("mana",0);
    this_object()->delete("busy_id");
	log_file("quest/TLBB", sprintf("%s(%s)quest�ڼ���tjf��ʧ�ܡ�\n", me->name(1),me->query("id")) );
  	return;
  }
     obj=new(__DIR__"npc/dlsdizi");
     obj->set("kill_id",me->query("id"));
     obj->set("type",1);
     obj->move(environment(me)); 
     obj->set_leader(me);
     obj=new(__DIR__"npc/dlsdizi");
     obj->set("kill_id",me->query("id"));
     obj->set("type",2);
     obj->move(environment(me)); 
     obj->set_leader(me);
     obj=new(__DIR__"npc/dlsdizi");
     obj->set("kill_id",me->query("id"));
     obj->set("type",3);
     obj->move(environment(me)); 
     obj->set_leader(me);

     //���֮������ͻ
     remove_call_out("busy");
     call_out("busy", 1); 
	 return;
}
void busy()
{
	object ob;
	ob=this_object();
	if(!ob->query("busy_id")) return;
    if(present(ob->query("busy_id"),ob)) call_out("busy", 1);   
	else ob->delete("busy_id");
}
int valid_leave(object me, string dir)
{
	if (me->query(QUESTDIR2+"start")
     &&me->query_temp(QUESTDIR2+"jiumozhi")
     &&!me->query_temp(QUESTDIR2+"kill_dizi")
     &&!me->query(QUESTDIR2+"over"))
		return notify_fail(RED"��Ҫ���ܣ�����ר�ĵ��Ԯ�����¡�\n"NOR);
		
  if(me->is_fighting()) return notify_fail(RED"��Ҫ���ܣ�����ר�ĵ��Ԯ�����¡�\n"NOR);	
  
	if ( me->query("family/family_name") != "������" 
	 && dir != "out" 
	 && me->query("shen") < 0
	 && objectp(present("wu seng", environment(me))))
		return notify_fail("��ɮ��ס�㣬˵�����������ڲ������������\n");
	return ::valid_leave(me, dir);
}
