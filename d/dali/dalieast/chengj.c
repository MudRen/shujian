// Room: /d/dali/chengj.c
// bbb 1997/06/10 
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "�ν����ɺ�");
	set("long", @LONG
�������滷ɽ�����汱����������ϲ���С��ǳ���в�ϸ�����������
«�����ײ�ƽ����������ʯ��������ܴ󡣺�ˮ��Ҫ������ˮ�ۻ�����������
����֧��ע�룬���гν������ӡ�����ӡ�����Ӽ�����̶����ˮ����Ȫˮ��
�룬����ĺ��ں���Ψһ�ĳ�ˮ�ڣ������̽������Ϻ���
LONG
	);
        set("outdoors", "����");

	set("exits", ([
            "north" : __DIR__"lunan",
            "east" : __DIR__"yzh",
            "southup" : "/d/group/entry/dleyd",
	]));

	setup();
}
