// by XiaoYao

inherit ROOM;
void create()
{
	set("short", "μ������");
	set("long", @LONG
�ںӺ�μ�ӻ���ƺӣ���������ˮ�ƣ�Ҳ�����˸������ɳ������Ӷ���
ɽ�������������������Ϸ�����һ�����֡���Լ���Կ���һƬ���¡�
LONG );
	set("outdoors", "�ƺ�");
	set("exits", ([
		"south" : __DIR__"huanghe1",
		"north" : __DIR__"hetao",
		"southwest" : "/d/nanyang/yidao4",
	]));
	setup();
}
