// Room: /d/city/yaopu.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "ҩ��");
	set("long", @LONG
	����һ��ҩ�̣�һ��ŨŨ��ҩζ���㼸����Ϣ�����Ǵ�ҩ���ϵļ��ٸ�С
������ɢ�������ġ���ҽƽһָ���ڲ輸�ԣ����Ժ��Ų裬��Ҳ������һ�ۡ�һ��
С���վ�ڹ�̨���к��Ź˿͡���̨������һ�ŷ��ƵĹ��(guanggao)��
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
