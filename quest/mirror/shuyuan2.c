// Room: /d/city/shuyuan2.c
// This is a room made by roommaker. write by Fan. :)
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "���������");
	set("long", @LONG
����һ����ż��ӵ�����������һ�Ŵ����⣬ΨһֵǮ��
ֻ��һ������ˡ�
LONG
	);
    set("objects", ([
]));

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"shuyuan",
]));
	setup();

}
  void init() 
  { 
       add_action("no_action", "shot");
       add_action("no_action", "array");
 } 
 int no_action(string str) 
{
       write(HIY"������������ \n"NOR); 
       return 1; 
} 
//�Ǿ���
int is_mirror() { return 1; }
