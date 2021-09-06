// Room: /d/mr/yanziwu.c
// this is made by beyond
// update 1997.6.20
// Modify by Lklv 2001.9.21

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short",WHT"Ժ��"NOR);
	set ("long",@long
��������Ļ��������֮��, Ļ������Ϧ�մ�����ĺ���, �����ռ�ʽ΢��
�������ȴһ��һ����⸴���ࡣ���书�������Ա�֮��, ��ʩ����, �˵�ʮ
��������
long);
	set("exits",([
		"south" : __DIR__"xiaojing2",
		"west" : __DIR__"houyuan1",
		"east" : __DIR__"wuchang",
	]));

	set("objects",([
		__DIR__"../npc/murong-fu" : 1,
	]));

	"/clone/board/murong_b.c"->foo();
	setup();
}

void init()
{
	if (this_player()->query("mr_job")){
		this_player()->add("job_time/Ľ��", this_player()->query("mr_job"));
		this_player()->delete("mr_job");
	}
	
	if(!this_player()->query("change_bug/fenglu")){
		this_player()->delete("fenglu");
		this_player()->set("change_bug/fenglu",1);
	}
}
