// Room: /city/dangpu.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
	����һ����������ƽ���Ƶĵ��̣�һ����߸ߵĹ�̨���������ǰ����̨
�ϰ���һ������(paizi)����̨���������ϰ壬һ˫�������۾��������´������㡣
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