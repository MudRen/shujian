// Room: /city/zahuopu.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "�ӻ���");
	set("long", @LONG
	����һ��СС���ӻ��̣�����С�������һ�أ�����һЩ�ճ���Ʒ������
�������������һֻ�����ϣ��к��Ź������ˡ���˵˽������Ҳ��һЩ���صĶ�����
̯������һ������(zhaopai)��
LONG
	);
	set("item_desc", ([
		"zhaopai": "���� \"list\" �г������\"buy\" ���ϰ幺�\n",
	]));
	set("exits", ([
		"north" : __DIR__"dongdajie1",
                "up" : __DIR__"garments",
	]));
	setup();
}

//�Ǿ���
int is_mirror() { return 1; }