inherit ROOM;

void create()
{
set("short", "ͷ��ɽ");
        set("long",@long
ͷɽ���ڻ���ɽ�����棬���ƻ�ͷ��������ǽ�����š���ӿ���ԡ��ĸ�
���֣���ʾ������󺣵�ԨԴ��ϵ��
long);
set("outdoors", "suzhou");
set("objects",([
__DIR__"npc/jian-ke" : 2,
]));
set("exits",([
"west" : __DIR__"wjszhuang",
"north" : __DIR__"huqiushan",
]));
set("incity",1);
	setup();
}
