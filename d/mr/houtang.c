// /u/beyond/mr/houtang.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIW"����"NOR);
         set("long", @long
�������һ��С������ͷ��һ��Ů���õ���ױ̨��������������֬�ۺС�
������һ�ų����ĺ�ľ������ֻҪ̧����ȥ��̫��������̲��������۵ס�
long);

	set("exits",([
		"north" : __DIR__"xiaoting",
	]));
	setup();
}

void init()
{
	add_action("do_zuan", "zuan");        
}

int do_zuan(string arg)
{
	object me = this_player();
	mapping myfam;
	
	myfam = (mapping)me->query("family");
	
	if(!arg || arg != "didao")
		return notify_fail("��Ҫ�������ꣿ\n");       
     
        if ( myfam && myfam["family_name"] != "����Ľ��")
            return notify_fail(" gg");
            
	message_vision("$Nһת����Ȼһ�����굽���²����ˡ�\n",me);
	me->move(__DIR__"didao");
	message("vision",me->name() + "��ˮ�ر�Ծ��������\n",environment(me), ({me}) );
        return 1;
}
