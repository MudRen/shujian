// Modify By River 98/12/
inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
���Ƿ����Ĵ����ϴ�֣�����������������������ߵ�����޲�������
�Ų����Ծ�����Ŀ��������ȥ�����߹�ȥ���Ǵ���ʹ��ˡ����洫��һ��ߺ��
����ԭ���Ǹ��ӻ��̣�����������ɧ�͹�˵���Ժ��������Ǵ������ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"nanjie4",
		"east" : __DIR__"shuyuan",
		"north" : __DIR__"dongjie7",
		"south" : __DIR__"zahuopu",
	]));
	set("outdoors", "����");
	setup();
}
