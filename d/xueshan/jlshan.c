 //      ���׶����

#include <ansi.h>

inherit ROOM;


void create()
{
        set("short",HIW"����ɽ"NOR);
        set("long",@LONG 
˳��Ϫ��������������·��ת��һ��Ϫ�壬��Ϫ�澹��Խ������Խ����
����ͷ������������������ǰһ����ӭ�����һ��ɽ�£������ͰΣ���ߺ�ֹ
ǧѰ�����°�����ϡϡ�ع����ʮ��ϸ�٣�����һ����̶����Լ��ʮĶ��̶��
��һ��С�·壬�߲Ŷ�ʮ���ɣ���Բ��Ķ�������ʯ൶룬������͸��������
�ϲ㣬��һ�����������ʯ��(dong)����ǰ����һ������ߵ�ƽ��ʯ�������
����ˮ�У����涼���岨���ƣ������ʸ���Խ�Ե������ޱȡ�        
LONG);
        set("exits",([
                "southdown" : __DIR__"tianxi",
 
        ]));
set("outdoors", "ѩɽ");
        setup();
//        replace_program(ROOM);
}
void init()
{
add_action("do_jump", ({"jump","tiao" }));
}
int do_jump(string arg)
{
    object me = this_player();
    if (arg!="dong")
    return notify_fail("��Ҫȥ���\n");
   if(me->query_skill("force",1)<=200)
   return notify_fail("���Ҫ�ٲ�����Ȼ�����ĵ��㺮����æ���˻�����\n");
   if (me->query_skill("dodge",1)<200)
   return notify_fail("��ǿҪ����С����ȥ���ͺ���̫��������ˮ��ɲ�����ġ�\n");
   message_vision(HIY"$N ����һ������������һ�ݣ�һʽ��Ƽ��ˮ����������ƮƮ���ڶ��ڡ�\n"NOR,me);
   me->move("jldong");
   return 1;
   }     
   		    