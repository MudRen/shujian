// Room: /d/taishan/.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�ഫ������ʼ����̩ɽ�����������������������͵������������±��꣬
���û���š���ˣ����ͷ�����������Ϊ�����򡹡�������֪����������һ
��޴�ķ���ʯ���������������ˡ����������Բ��������������ڲ�Զ������
һ������ƺ����˵������ʼ�ʵ�����ʵ�λ�á�����������ɽ���߱�ᵽ��ʮ
���̵���ڡ�
LONG
	);

	set("exits", ([
		"northup" : __DIR__"longmen",
		"southdown" : __DIR__"ertian",
	]));

        set("objects",([
                __DIR__"npc/jian-ke3" : 1,
                __DIR__"npc/dao-ke3" : 1,
	]));

	set("outdoors", "̩ɽ");
	setup();
}

