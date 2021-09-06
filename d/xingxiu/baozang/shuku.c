//tangfeng@SJ 8/2004

#include <ansi.h>
#include <room.h>
inherit ROOM;
#define QUESTDIR5 "quest/ѩɽ�ɺ�/����/"
#define QUESTDIR4 "quest/ѩɽ�ɺ�/�书/"

void create()
{
        set("short",BLU"�鷿"NOR);
        set("long", @long
��������ܣ������ƺ��Ǹ��鷿�����Ǽ�����һ����Ҳû�У�����������
�ĺۼ���û�С������Ա��Ǹ����ӣ��м������ѿ����Ա�Ӧ���Ǽ������衣
long);
        set("exits", ([
                "west" : __DIR__"tiantan",
                "south" : __DIR__"midong1",
                "east" : __DIR__"midong1",
                "north" : __DIR__"midong1",
        ]));
        set("quest", 1);
        set("baozang",1);
        setup();
}
void init()
{
        add_action("do_search", "xunzhao");
        add_action("do_search", "dig");
        add_action("do_search", "search");
        add_action("do_move", "move");
        add_action("do_push", "push");
        add_action("do_push", "tui");
        add_action("do_bang", "bang");
        add_action("do_move", "zhuan");
}
int do_search(string arg)
{
     object me,obj;
     me = this_player();
     if (me->is_busy() || me->is_fighting())
                   return notify_fail("����æ���ģ�\n");
      message_vision(HIY"$N���ڵ��ϣ��Ĵ�Ѱ�ҡ�\n"NOR, me);
      if(!wizardp(me)) me->start_busy(1);
      if(me->query(QUESTDIR5+"yupei")||!me->query(QUESTDIR4+"lengquanshengong")||me->query(QUESTDIR4+"lengquanshengong_teach"))
      {
         tell_room(environment(me), me->name() + "���˰��죬ֻŪ��һ���ࡣ\n", ({ me }));
         return notify_fail("�����˰��죬ʲôҲû�ҵ���\n");
      }
      obj = new("/d/xingxiu/baozang/obj/yuqi");
      obj->set("owner",me->query("id"));
      obj->set("quest",1);
      obj->set("long", HIC"���Ƕ�����ʯ��Ʒ�е�һ��������������ɽ��������һ����\n"
                      +"�������һ�����硱�֡�\n"NOR);
      obj->move(me);
      message_vision(WHT"$N����ֽ����ʾ�ķ�λ����û�з����ؼ�����ȴ����һ��"+obj->name()+WHT"��\n"NOR, me);
      log_file("quest/FEIHU", sprintf("%s(%s)�ҵ�������壬�⿪��Ȫ�񹦡�����%d��\n", me->name(1),me->query("id"),me->query("combat_exp")) );
      me->set(QUESTDIR5+"yupei",1);
      me->start_busy(2);
      return 1;
 }

int do_push(string arg)
{
	object me,*ob;
  int i;
  me = this_player();
	if (me->is_busy() || me->is_fighting())
		      return notify_fail("����æ���ģ�\n");
	if ( !arg || (arg != "zhuo zi" &&arg != "zhuozi" &&arg != "anmen" && arg != "wall"))
       		return notify_fail("��Ҫ�ƶ�ʲô��\n");
  ob = deep_inventory(me);
  i = sizeof(ob);
  while (i--)
  if (ob[i]->is_character())
       		return notify_fail("�㱳��һ�ˣ��޷��ƶ���\n");
  if(arg=="zhuo zi"||arg=="zhuozi")
  {
    if(!me->query_temp(QUESTDIR5+"bang_zhuozi"))
       		return notify_fail("����̫��ɢ���޷��ƿ���\n");
    if(me->query_temp(QUESTDIR5+"move_zhuozi"))
    {
    		message_vision(HIY"$N���������ƻ�ԭ����λ�á�\n"NOR, me);
	      me->delete_temp(QUESTDIR5+"move_zhuozi");
        me->start_busy(1);
  	    return 1;
    }
	  message_vision(HIG"$N��������õ�����ȫ���Ƶ������һ�ߡ�\n"NOR, me);
	  me->set_temp(QUESTDIR5+"move_zhuozi",1);
    me->start_busy(1);
  	return 1;
  }
  if(!me->query_temp(QUESTDIR5+"move_huapen"))
       		return notify_fail("���ŵĻ���û�д򿪣��޷��ƿ���\n");
  if(!me->query_temp(QUESTDIR5+"move_zhuozi"))
       		return notify_fail("�������赲���޷��ƿ���\n");
  if(me->query_temp("no_bug")) 
                    return notify_fail("���Ѿ���ȥ���ˡ�\n");
	message_vision(HIG"$N�����ƿ���İ��ţ��������ŷ켷�˽�ȥ��\n"NOR, me);
	me->move(__DIR__"mishi");
	me->delete_temp(QUESTDIR5+"move_zhuozi");
	me->delete_temp(QUESTDIR5+"move_huapen");
        me->delete_temp(QUESTDIR5+"bang_zhuozi");
        me->delete(QUESTDIR5+"shuku");
  me->start_busy(1);
	tell_room(environment(me), me->name() + "�����漷�˽�����\n", ({ me }));
	return 1;
}
int do_move(string arg)
{
	object me;
  me = this_player();
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");
	if ( !arg || (arg != "huapen" && arg != "hua pen"))
       		return notify_fail("��Ҫת��ʲô��\n");
  if(me->query_temp(QUESTDIR5+"move_huapen"))
  {
  	message_vision(HIG"$N�ѵ��ϵĻ���ת��ԭλ��\n"NOR, me);
	  me->delete_temp(QUESTDIR5+"move_huapen");
    me->start_busy(1);
    return 1;
  }
	message_vision(HIG"$Nת��ת���ϵĻ��衣\n"NOR, me);
	me->set_temp(QUESTDIR5+"move_huapen",1);
  me->start_busy(1);
	tell_room(me,"��ͻȻ�������Ӻ���ƺ��е����š�\n");
	return 1;
}
int do_bang(string arg)
{
	object me,ob;
  me = this_player();
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");
        if ( !arg || (arg != "zhuo zi" && arg != "zhuozi"))
       		return notify_fail("��Ҫ��ʲô��\n");
  if(me->query_temp(QUESTDIR5+"bang_zhuozi"))
       		return notify_fail("���Ѿ�����ˡ�\n");
  if(me->query_temp("no_bug")) 
                return notify_fail("���Ѿ�����ˡ�\n");
  if(!(ob=present("sheng zi",me))) 
       		return notify_fail("��û�����ӣ���ʲô��\n");
       		
	message_vision(HIG"$N����Ҫ��ɢ�����ӣ������Ӱ���һ��\n"NOR, me);
	me->set_temp(QUESTDIR5+"bang_zhuozi",1);
  me->start_busy(1);
	return 1;
}
