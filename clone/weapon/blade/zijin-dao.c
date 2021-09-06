// zijin-dao.c �Ͻ�

#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
        set_name( HIM"�Ͻ�"NOR , ({ "zijin dao", "dao","blade" }));
        set_weight(17500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIM"���ǰ���ɫ�ı�����ֻ���ڹ�������˲��ܷ�����ȫ����������\n"NOR);
                set("value", 10000);
                set("unique", 1);
                set("rigidity", 3);
                set("weapon_prop/parry", 2);
                set("wield_neili", 500);
                set("wield_maxneili", 900);
                set("wield_str", 22);
                set("treasure",1);
                set("material", "steel");
        }
        init_blade(30);
        setup();
}

int wield()
{
        object ob = environment();
        int ret;

	if( !ob || !living(ob) ) return 0;
	
	if( (int)ob->query_skill("force") > 150 ) {
		set("weapon_prop/damage" , ob->query_skill("force")/5 );
        	if( query("weapon_prop/damage") > 60 )
        		set("weapon_prop/damage" , 60 );
        }
        else
            set("weapon_prop/damage" , 30 );
            
        if(!query("weapon_prop/damage")) return 0;
        else if (ret=::wield()) return ret;
        return 1;
}
