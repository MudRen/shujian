inherit ROOM;

void create()
{
set("short","����ͤ");
set ("long",@long
����ͤ��ǧ��ʯ���࣬���ڱ��Ρ�ͤ��Ƕ����ʯ�����ֱ��������γ�
�������ƴ�������������ͤ����������ʯ�������������˵��ԭ���Σ�Ԫ
����Ԫ����Ԫ�����������������Լ����񳯻��������١���
long);
set("outdoors", "suzhou");
set("objects",([
__DIR__"npc/wei-shi3" : 4,
]));
set("exits",([
"north" : __DIR__"bailianchi",
"west" : __DIR__"qianrenshi",
]));
setup();
}
