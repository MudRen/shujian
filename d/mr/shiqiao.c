#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short",HIW"Сʯ��"NOR);
	set("long",@long
����һ��СС�İ�ʯ���š����±��̵ĺ�ˮ������΢����Զ���ĺ����ϴ�
�������������Զ����ֻԧ����һ��Ϸˮ�����ߵ��������ź����ϴ�����΢��
ʱ��ʱ��ҡ���š�
long);
// will add a npc to ask chuan
	set("outdoors","Ľ��");
	set("exits", ([
		"south" : __DIR__"testmatou1",
		"northwest" : __DIR__"hubian2",
	]));
	setup();
}

void init()
{
	add_action("do_push", "push");        
}

int do_push(string arg)
{
	if (arg != "����" || query("exits/down")) return notify_fail("��Ҫ��ʲô��\n");
	
	message_vision("��ͷͻȻ����ȥ��һ�飬¶��һ���ض���\n",this_player());
	
	set("exits/down", __DIR__"didao");
	
	remove_call_out("close");
	call_out("close", 4);

	return 1;
}

void close()
{
	tell_room(this_object(), "���滺����������������Ҳ��ʧ�����ˡ�\n");
	delete("exits/down");
}

int valid_leave(object me, string dir)
{
	if (me->query("family/family_name") != "����Ľ��" && dir=="down")
		return notify_fail("һλĽ�ݼҶ���Ȼ�����������˳�������ס����˵�����ô�Ľ���ܵ���������\n˵�꣬��λ�Ҷ�����һ�Σ����˻ذ�����\n");

	return ::valid_leave(me, dir);
}
