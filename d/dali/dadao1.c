// Room: ��� 1
// bbb 1997/06/11
// Modify By River 98/12 
inherit ROOM;

void create()
{
        set("short", "���");
	set("long", @LONG
�����ڴ�ɽ�������˳�������ǰ��Ȼ���ʣ�һ����ֱ��ʯ����ͨ��ǰ����
���ܿ�ʼ��һЩ���ӵ��������������������������ϱ������ս����ʱ��Ϊ
�����,���������ݣ������������ϣ������ȿ�����Ϊ��گ����Ϊ����ء�
LONG
	);
        set("outdoors", "����");
	set("exits", ([ /* sizeof() == 1 */
		"north" : __DIR__"shanlu4",
		"south" : "/d/group/entry/dlndao2",
		"southwest" : __DIR__"yuxu/xiaodao1",
        ]));
	set("no_clean_up", 0);

	setup();
}
