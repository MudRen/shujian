inherit ROOM;

void create()
{
set("short","ǧ��ʯ");
set ("long",@long
�ڻ���ɽ���ģ���һ��ǧ��ʯ����ʯ�ʰ��Ϻ�ɫ����������бʯ����
ƽ̹��ʯ���縫������˵����Ĺ���ɺ����ӷ����й¶��Ĺ���ܼٽ�Ĺ��
ף�ƹ���֮������ǧ��������ȫ��ɱ¾����Ѫ��͸ʯ�У��ɰ���ɫ��
long);
set("outdoors", "suzhou");
set("objects",([
__DIR__"npc/wei-shi2" : 4,
]));
set("exits",([
"east" : __DIR__"erxianting",
"northwest" : __DIR__"zhishuangge",
"north" : __DIR__"shijianshi",
]));
setup();
}
