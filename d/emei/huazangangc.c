// huazangangc.c
// �㳡 
inherit ROOM;
void create()
{
	set("short","�����ֹ㳡");
	set("long",@long
�����Ƕ��һ����ֵĹ㳡������������ש����ǰ����һ��̨�ף�ͨ����
�۱����ǰ�и�����ߵĴ���¯����¯ǰ����̨�ϣ�������գ�����Ʈ�ơ�
�㳡���м���Сʦ̫�����������Դ����Ҹ���һ������ͨ���
long);
	set("exits",([
	    "east" : __DIR__"dcelang",
	    "west" : __DIR__"xcelang",
	    "north" : __DIR__"huazanganzd",
	    "southup" : __DIR__"daxiong",
]));
        set("objects",([
		CLASS_D("emei") + "/jing-xu" : 1,
          ]));
	set("outdoors", "����ɽ");
	setup();
        "/clone/board/emei_b"->foo();
}
