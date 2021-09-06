// Room: /d/huashan/jinshe/obj/jinshesword.c
// Date: Look 99/03/25

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name(HIY"���߽�"NOR,({ "jinshe sword", "sword" }) );
        set_weight(80000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1);
                set("rigidity", 8);
		set("sharpness", 8);
                set("material", "steel");
                set("weapon_prop/dodge", 20);
                set("weapon_prop/parry", 20);
                set("treasure",1);
                set("long", "��ѽ�����һ�����ߣ�����Ӳӣ���Ϊ���� ��\n������һ��Ѫ�ۣ����������͵İ��⣬���ǹ��졣\n");                
                set("unwield_msg", HIY "$N����һ�ӣ����н��߽��Ѳ�����Ӱ����̬�����ޱȡ�\n" NOR);
                set("unequip_msg", HIY "$N����һ�ӣ����н��߽��Ѳ�����Ӱ����̬�����ޱȡ�\n" NOR);
        }
        init_sword(80);
        setup();
}

void init()
{
    add_action("do_wield","wield");
}

int do_wield(string arg)
{
     object me,ob;

     me = this_player();
     ob = this_object();

      
      if( !arg ) return 0;
      if(arg == "jinshe sword" || 
         arg == "sword") {      
        if((int)me->query("max_neili", 1) < 1200 ||
           (int)me->query("neili", 1) < 300  ){
           tell_object(me,"��о�ȫ����Ϣ���ڣ�ԭ���������������᲻����߽���\n");
           return 1;
           }
        if((int)me->query_str() < 24){
           tell_object(me,"���������߽�����������������ֻ�����ա�\n");
           return 1;
           }
        ob->wield();
        message_vision(HIY"$N΢һ�趯��һ��ҫ�۵Ľ������$Nȫ���������ߣ���â��ס��$N����
�Ѷ��˱��������������α���������ĺ���ӳ�ճ�$N���ϸ��ֳ��������顣\n"NOR, me);
        me->add("neili", -100);
        return 1;
        }
}