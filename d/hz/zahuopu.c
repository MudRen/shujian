// /u/beyond/hz/zahuopu.c  �ӻ���
 
inherit MISC_ROOM;
void create()
{
	set("short","�ӻ���");
	set("long", @LONG
����һ��СС���ӻ��̣�����С�������һ�أ�����һЩ�ճ���Ʒ����
�������������һֻ�����ϣ��к��Ź������ˡ���˵˽������Ҳ��һЩ����
�Ķ�����̯������һ������(zhaopai)��
    ��ǰ���˸�����(sign)��
LONG
	);

	set("item_desc", ([
		"zhaopai": "���� \"list\" �г������\"buy\" ���ϰ幺�\n",
	]));
	set("exits", ([
		"east" : __DIR__"qsddao5",
	]));
	set("objects", ([
		__DIR__"npc/zhlaoban": 1,
	]));

	set("coor/x",90);
  set("coor/y",-330);
   set("coor/z",0);
   setup();
}

