// /d/mingjiao/bhd/congling1.c
// Jay 4/3/97 -qingyun
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
string look_tree();
void create()
{ 
        set("short",HIG"����"NOR);
        set("long", @LONG
����һƬ���Ĵ��֡���ʮ�ɸߵ���ľ(tree)����һ�飬��ʵ��֦Ҷ��һ
�����ɡ��������գ��������ڵ�˿��Ҳ�ޡ����ڴ�����ʱ����ܾã��ֺ���
���������Զ�ֲ������ܶ࣬��������Ӧ�о��С�ż�����г����޳������ˡ�
��һ�߽������������ɭ�ֵġ�
LONG);    
	set("exits", ([
                "south" : __DIR__"cling",
	]));    
        set("item_desc", ([
                "tree" : (: look_tree :),
          ]));
        set("objects",([
		"/d/mingjiao/npc/xiong"  :  2,
	]));
        set("tree_count", 2);
	set("outdoors","����");
        setup();
}

void reset()
{
        set("tree_count", 2);
        ::reset();
}

void init()
{
	add_action("do_chop","chop");
        add_action("do_chop","��");
}

int do_chop(string arg)
{
        object me, weapon;
        me = this_player();
        weapon = me->query_temp("weapon");
        if( arg=="tree" || arg=="Tree" || arg=="��ľ" ) {
             if(me->is_busy()) return notify_fail("����æ���ء�\n");
             if(query("tree_count") < 1) return notify_fail("ʣ�µ���ľ��̫���ˣ��㻹�������Ұɡ�\n");
             me->start_busy(1);
             if(!weapon){
                     message_vision("\n$N�˹�������һ�ƴ�����ǧ��������ʵ�������ϣ�ʹ��$P����ֱ���µ���\n\n",me);
                     me->set_temp("last_damage_from", "���Լ��ķ�������");
                     me->receive_wound("qi", 50);
                     me->receive_damage("qi", 50);
                     EMOTE_D->do_emote(me,"nocry");
                     return 1;
             }
             else if(weapon->query("flag")!=4){
                     message_vision("\n$N����$n��������һ�����á�\n"+
                                    "������һ�����¸�����֦�������ô���$Pͷ�ϣ���ʱ���˸������\n",me, weapon);
                     me->set_temp("last_damage_from", "����֦ѹ");
                     EMOTE_D->do_emote(me,"pain");
                     EMOTE_D->do_emote(me,"cry");
                     me->receive_wound("qi", 50);
                     me->receive_damage("qi", 50);
                     return 1;
             }
             else{
                     message_vision("\n$N����$n���������Ͽ���������������������\n",me, weapon);
                     if(random(100) > 90){
                          message_vision("\nֻ������һ���������ľ���㱻$N�����ˡ�\n",me);
                          new("/d/mingjiao/obj/tree")->move(this_object());
                          add("tree_count", -1);
                     }
                     me->receive_damage("jingli", random(20)+10);
                     me->improve_skill(weapon->query("skill_type"), random(me->query("str")));
                     return 1;
             }
        }
}    
   
string look_tree()
{
       return
       " 
                            m
           *               m*m
         *****            m***m
        ***|*/*          m*****m
       ****|****        mm*****mm
         **Y**          mm**Y**mm
^^    ^^   |   ^^  ^^      *|*     ^^   ^^
------------------------------------------

�������ľ�ߴ�ï�ܣ����ɽ�ʵ�����ʺ����촬����\n";
}
