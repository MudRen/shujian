// Room: /city/bingyin.c
// YZC 1995/12/04 
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "��Ӫ");
	set("long", @LONG
	�����Ǳ�Ӫ���������鵽�����ǹٱ����е����佫��ָ�����жӲ�����
�еĶ������������е����š�����������Ϣ����ǽ��������˧��������ɫ��Ѱ��
�����ܡ����������������ȫ�������Χ�˹��������ƿ�����̫��ϱ���һ��
��(men)��
LONG
	);
	set("item_desc", ([
		"men" : "����һ�ȼ�������š�\n",
	]));
	set("exits", ([
		"south" : __DIR__"bingqiku",
		"north" : __DIR__"bingyindamen",
	]));

        create_door("south", "����", "north", DOOR_CLOSED);
	setup();
}
//�Ǿ���
int is_mirror() { return 1; }
