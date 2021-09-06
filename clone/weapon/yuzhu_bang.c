// bamboo_stick.c �����
// by shang 97/6
// modified by explorer, 9/11/97

#include <ansi.h>
#include <weapon.h>

inherit STICK;

string* skills = ({
        "stick",
        "bangjue",
});

void create()
{
        int i;

        i = 0;
        if (random(10) > 6) i = 1;

        set_name(HIG "�����" NOR, ({"yuzhu bang", "bang", "stick"}));
        set_weight(5000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        set("long",HIG + "һ������������Ө,ͨ����̵����,,���ŵ�������� ��\n" NOR);
                set("value", 10000);
                set("material", "bamboo");
                set("weight", 10000);
                set("treasure", 1);
                set("unique", 1);
                set("weapon_prop/parry", 3);
                set("rigidity", 9);                
                set("wield_msg", "$N���һ�����������������ץ�����С�\n");
                set("unwield_msg", "$N�����е������Ȳ�����С�\n");
                set("skill", ([
                     "name": skills[i],
                     "exp_required": 50000,
                     "difficulty": 24,
                     "max_skill": 100,
                ]) );
        }
        init_stick(120);
        setup();
}       

void init()
{
        if( this_player() == environment() )
                add_action("do_study", "study");
}

int do_study(string arg)
{
        int damage;

        object me = this_player();

        if ( arg != "bang" && arg != "stick" )
            return notify_fail("��Ҫѧʲô��\n");

        if ((int)me->query_skill("literate", 1) < 30 )
            return notify_fail("���ѧʶ��û�������ϵĿھ���\n");

        if ((int)me->query_skill("bangjue",1) > 120)
            return notify_fail("���Ѿ����ܴӰ���ѧ���κζ����ˡ�\n");

        if ((int)me->query_skill("stick", 1) < 60 )
            return notify_fail("��Ļ�������̫��, ����᲻�˰�����\n");

        damage = 2400 / (int)me->query("int");
        me->receive_damage("jing", damage);
        me->receive_damage("jingli", damage);
        me->improve_skill("bangjue", me->query("int"));
        message_vision("$N���Ű��ϵ��ּ�, ��˼���ѡ�\n", me);
        return 0;
}
