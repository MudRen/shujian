// Room: /city/garments.c

inherit ROOM;

void create()
{
	set("short", "���µ�");
	set("long", @LONG
�������������¹󸾳���֮��������Ҳ��������Ҳң�֬�ۺ�ɡ���Ϊ
��������ʱ�У�һֱ�����������Ե�װ�硣�����Ǹ��ܿ��˵�СŮ��������
��һ������ʱ���������������Ů�˼���һ�𣬻�������������
    ���ſں�������д�ż�������(zi)����������С���ֱʡ�
LONG );
	set("item_desc", ([
		"zi": "list ����\"buy\" ��\n",
	]));
	set("exits", ([
		"down" : __DIR__"zahuopu",
	]));

	setup();
}

//�Ǿ���
int is_mirror() { return 1; }