 // /u/beyond/mr/shuxie.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIW"����ˮ�"NOR);
         set("long",@long
��䷿��С������, ��Ϊ���š�С���Ҷ���д��"����ˮ�"�ĸ�����, ��
����Ϊ������������һ��С·����֪��ͨ������ġ�����ǰ�ߣ��͵��ˡ�����
�롱���ϱ���ˮ鿵ĺ�Ժ��
long);
	set("exits",([
		"north" : __DIR__"anbian2",
		"west" : __DIR__"anbian4",
		"south" : __DIR__"houyuan1",
	]));
	set("objects",([
		__DIR__"../npc/azhu" : 1,
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
	
	if (!arg || arg != "didao" || me->is_busy())
		return notify_fail("��Ҫ�������ꣿ\n");       

        if (myfam && myfam["family_name"] != "����Ľ��")
		return 0;
            
	message_vision("$Nһת����Ȼһ�����굽���²����ˡ�\n",me);
	me->move("/d/mr/didao");
	message("vision",me->name() + "��ˮ�ر�Ծ��������\n",environment(me), ({me}) );
        return 1;
}
