#include <ansi.h>
#include <armor.h>
inherit CLOTH; 
void create()
{
	set_name(YEL"��⬼�"NOR, ({ "ruanwei jia","ruanwei", "jia" }) );
	set_weight(2500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�һ���������⬼ף��ʵؼ��ͣ���ǹ���롣\n");
		set("unit", "��");
                set("unique", 1);
                set("treasure",1);
		set("value", 1000000);
		set("material", "softsteel");                 
        set("armor_prop/armor", 100);
	}
	setup();
}

int ob_hit(object ob, object me, int damage)
{
        object weapon = ob->query_temp("weapon");
        int p;
        string msg;

	::ob_hit();
        if(!weapon&&(random(10)<5)) {
            msg = "ֻ������Ӵ��һ��������$N��ָȫ������⬼׵Ĵ��ϣ���ʱ�̵���Ѫ���죡\n";
            ob->receive_damage("qi", damage/8);
            ob->receive_wound("qi", damage/10);
            p = (int)ob->query("eff_qi")*100/(int)ob->query("max_qi");
            msg += "( $N"+COMBAT_D->eff_status_msg(p)+" )\n";
            message_vision(msg, ob);
            return -damage/3;
         }        
}
