// /u/beyond/mr/shiqiao1.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIW"Сʯ��"NOR);
         set("long",@long
����һ��СС�İ�ʯ���š����±��̵ĺ�ˮ������΢����ʯ�ŵĶ�����һ
������ʯ�̳ɵ�С������������٢��ɽׯ��ǰԺ��
long);
	set("outdoors","��٢��ɽׯ");
	set("exits",([
             "east" : __DIR__"xiaojing5",
             "west" : __DIR__"qianyuan",
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
            return notify_fail("�㲻��Ľ�ݼҵ��ˣ������");
            
	message_vision("$Nһת����Ȼһ�����굽���²����ˡ�\n",me);
	me->move("/d/mr/didao");
	message("vision",me->name() + "��ʯ�ű�Ծ��������\n",environment(me), ({me}) );
        return 1;
}
