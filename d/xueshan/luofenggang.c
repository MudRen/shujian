// Room: luofenggang.c ����

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǹ�������ɽ�ԣ�һ���Ǽ�ʮ�ɸߵĶ��£���һ����Ͽ�ȡ������Ϻ��
��ѩ�㱻������ҫ�������ڻ������ϳ���ɽ�����ҵĴ��������ﾭ���������С
С��ѩ����ƽ������������û�����ġ�
LONG
	);
	set("exits", ([
		"east" : __DIR__"fengjiantai",
	]));

	set("coor/x",-310);
  set("coor/y",150);
   set("coor/z",10);
   setup();
}
void init()
{
//add_action("do_say","say");
        add_action("do_jump", "tiao");
        message_vision(HIW"���ۡ���һ����һ��Сѩ��������ͷ�ϣ����˿�ȥ��\n"NOR,this_player());
}
int do_say()
{
       object *ob,thisroom,room;
       int i;
       thisroom = find_object(__DIR__"luofenggang");
       room = find_object(__DIR__"xuegu");       
       message_vision(HIW"$N��˵��һ���֣�ͻȻ���ԡ���¡¡�����������ڣ�̧ͷ��ȥ��ֻ���¶���
 �����Ļ�ѩ���籼�׹���������\n\n"+HIR"ѩ���ˣ�\n\n"+
HIW"������ؾ��֮ʱ�����˷·������е�һҶС�ۣ��޿ɿ���......\n\n
�ɱ��Ļ�ѩ�����һ�������Ƶ��ڵ�......"NOR, this_player());
	ob = all_inventory(thisroom);
	for(i = 0; i < sizeof(ob); i++) {
		if (living(ob[i])) {
	tell_object(ob[i],HIW"���ɽ�Ϲ�����ȥ��\n"NOR);
	ob->move(__DIR__"xuegu");
	tell_room(room,HIW+ob[i]->name()+"��ɽ�Ϲ���������ž��һ������ˤ�ڵ��ϡ�\n"NOR,({ob[i]}));
 if(ob[i]->query("combat_exp")<200000)
	ob[i]->unconcious();
	   }
	}
	return 1;
}
int do_jump(string arg)
{
       object me,room;
       me = this_player();
       room = find_object(__DIR__"xuegu");       
       if (arg != "down" || !arg )
           return 0;
       message_vision(HIW"$N����������˫����չ���Ծ������һֻ������ȵ�������ȥ��\n"NOR, me);
	me->move(__DIR__"xuegu");
message_vision( HIW "$N�ӿ��м������£��͵�һ���������ѩ�ѣ�ת�����˳�������Ȼû�����ˣ�\n"NOR,me);
	return 1;
}
