
#include <ansi.h>
#include <room.h>
inherit ROOM;
#define QUESTDIR5 "quest/ѩɽ�ɺ�/����/"
#define JADE    "/d/zhiye/obj/othermaterial" //��

void create()
{
        set("short",YEL"������"NOR);
        set("long", @long
����Ӧ����һ�����䳡���߱����ң�����ɢ�������߰���ı�����ʮ֮��
�Ŷ��ǹŽ��������߳ߣ���̽����磬ֻ�Ǵ�����ڰ߲���
long);
        set("exits", ([
                "east" : __DIR__"tiantan",
                "south" : __DIR__"midong3",
                "west" : __DIR__"midong3",
                "north" : __DIR__"midong3",
        ]));
        set("quest", 1);
        set("baozang",1);
        setup();
}
void init()
{
        add_action("do_search", "search"); 
        add_action("do_search", "xunzhao"); 
        add_action("do_search", "dig"); 
}
int do_search(string arg)
{
	object me,obj;
  me = this_player();
	if (me->is_busy() || me->is_fighting())
		      return notify_fail("����æ���ģ�\n");
  message_vision(HIY"$N���ڵ��ϣ��Ĵ�Ѱ�ҡ�\n"NOR, me);
  if(!wizardp(me)) me->start_busy(1);
  if(me->query(QUESTDIR5+"bingqiku")>=2||random(2))
  {
         tell_room(environment(me), me->name() + "���˰��죬һ��С�Ĳȵ���һ�������㣬ˤ�˸����˲档\n", ({ me }));
       return notify_fail("�����˰��죬ʲôҲû�ҵ���\n");
  }
    me->add(QUESTDIR5+"bingqiku",1);
  obj = new(JADE);
  obj->set_level(3+random(3));
        obj->move(me);
        message_vision(WHT"$N����һ��"+obj->name()+WHT"��\n"NOR, me);
  log_file("quest/FEIHU", sprintf("%s(%s)�ҵ�������ı���%s������%d��\n", me->name(1),me->query("id"),obj->query("name"), me->query("combat_exp")) );
  me->start_busy(2);
	return 1;
}
