// Room: /city/dangpu.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "�ƾɵ���");
	set("long", @LONG
	����һ����������ƽ���Ƶĵ��̣��ϰ��ƶ������ˡ�
LONG
	);

	set("item_desc", ([
		"paizi": @TEXT
    �����̲����ۺ�ͯ�����ۣ���ӭ�ݹˣ����Ա��ܡ����Ŀ���������
����(list)������(buy)������(value)���䵱(pawn)�����(redeem)����
��(sell)���ֻ��
TEXT
	]) );

	set("exits", ([
		"west" : __DIR__"nandajie1",
	]));
	setup();

}
//�Ǿ���
int is_mirror() { return 1; }