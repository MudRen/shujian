inherit ROOM;

void create()
{
set("short", "�Խ�ʯ");
        set("long",@long
��ɽ���������Խ�ʯ������Բ�Σ���������������ѵ��ѷ죬�ഫ����
�á��ɽ�������Īа������Ϊ�����������ʯ������ʯ�Կ���Ԫ��������
ʫ�䡰����һ�������ˮ��������ΰ���󣬲�ն�Ը�ͷ������ʫ�䡣
long);
set("outdoors", "suzhou");
set("objects",([
__DIR__"npc/wei-shi1" : 4,
]));
set("exits",([
"northeast" : __DIR__"muniangmu",
"north" : __DIR__"zhenshi",
"south" : __DIR__"qianrenshi",
"westdown" : __DIR__"wjszhuang",
]));
setup();
}
