// Room: /d/fuzhou/zahuopu.c
// Lklv 2001.9.7
inherit MISC_ROOM;

void create()
{
	set("short", "�ӻ���");
	set("long", @LONG
����һ��ר��Ů����Ʒ��С�̡�������Ȼ��С�����Ǻ��ܸ����ľ���Ļ�
ӭ�����ϱ���һ������Ĺ�̨�������ź��λ��վ��һλ�����š���������ͷ
��ĸ�Ů���ڹ�̨ǰ��ѡ������
    ��ǰ���˸�����(sign)��
LONG
	);
	set("exits", ([
                "west" : __DIR__"xixiang",
	]));

    	set("objects", ([
        	__DIR__"npc/chen" : 1,
	]) );
	set("indoors", "����");
	setup();
}
