// Room: /d/city/yaopu.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "�ƾ�ҩ��");
	set("long", @LONG
	����һ��ҩ�̣���Ȼ�ưܲ�������һ��ŨŨ��ҩζ�������㼸����Ϣ��
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "guanggao" : "�����������ҩƷ��
��ҩ��	��ʮ������
������ҩ���ϰ����顣
",
]));

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dongdajie2",
"north" : __DIR__"yaopuls",
]));
	setup();
}

//�Ǿ���
int is_mirror() { return 1; }
