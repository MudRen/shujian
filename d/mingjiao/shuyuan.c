// shuyuan.c ��Ժ
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short", HIC"��Ժ"NOR);
       set("long", @LONG
���������̲���֮�أ�һ���ŵ��������������ţ�����Ϸ��Ÿ��ָ���
���鼮��Ժ�ھ������˴�ɨ�������һ����Ⱦ��������̵������ڴ�ר�ĵ���
�����˴˾����ĵġ�������һ��ͨ������õ����ȡ�
LONG);    
       set("exits", ([
             "east" : __DIR__"wu1",		
       ]));             
       set("objects",([
	    "/d/baituo/obj/book1" : 1,
//          "/d/baituo/obj/book5" : 1,
	    "/d/shaolin/obj/fojing11" : 1,
            "/d/shaolin/obj/fojing21" : 1,
	    "/d/wudang/obj/ddj1" : 1,
            MEDICINE_D("m-book7") : 1,
            MEDICINE_D("m-book8") : 1,
            __DIR__"npc/yahuan" : 1,
        ]));
        set("no_fight", 1);
	setup();
}

int valid_leave(object ob, string dir)
{
	string* book = keys(query("objects"));
	object* shu = deep_inventory(ob);
	int i = sizeof(shu), count = 0;
	while (i--)
		if (member_array(base_name(shu[i]), book) != -1) count++;
	if (count > 1) return notify_fail("��һ��������ô�飬���ù�����\n");
        if (count) ob->set_temp("marks/Ժ1", 1);
	return ::valid_leave(ob, dir);
}
