inherit ROOM;

void create()
{
    set("short","����");
    set("long",
"������һƬ���֣������������ˣ����ֳɳ��ܿ죬�Ѿ��γ���һƬ
�ܴ��������Եú�ï�ܡ��������߾����϶ɿ��ˡ�\n");
    set("outdoors", "��ɽ");
    set("exits",([
        "northwest" : __DIR__"shulin1",
        "south" : __DIR__"dukou",        
]));
   setup();
}