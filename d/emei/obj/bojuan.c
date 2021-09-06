inherit ITEM;
inherit F_AUTOLOAD;

void create()
{
        set_name("����", ({ "bo juan", "bo", "juan" }));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ�Ų�������д���˾�������֡�\n");
                set("treasure", 1);
                set("value", 200000);
                set("material", "skin");
                set("no_drop", 1);
                set("no_give", 1);
                set("no_get", 1);
                set("no_steal", 1);
        }
}

void init()
{
    add_action("do_study",({"yandu", "kan"}));
}

int do_study(string arg)
{
    int cost, my_skill;
    object me=this_player();
    object where = environment(me);
    if (!arg || !(arg=="bo juan" || arg=="bo" || arg=="juan"))
        return 0;
    if (me->is_busy())
        return notify_fail("��������æ���ء�\n");
    if (where->query("sleep_room"))
        return notify_fail("���Ҳ��ܶ��飬��Ӱ�������Ϣ��\n");
    if( me->is_fighting() )
        return notify_fail("���޷���ս����ר�������ж���֪��\n");
    if( !me->query_skill("jiuyin-baiguzhua") )
        return notify_fail("���޷�����������ѧ���κζ�����\n");
    if( !me->query_skill("literate", 1) )
        return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
    if (!random(5))
        message("vision", me->name() + "��ר�ĵ��ж�����\n", environment(me), me);
    if( (int)me->query("potential") < 1 )
        return notify_fail("���Ǳ���Ѿ������ˣ�����ô��Ҳû�á�\n");
    if( (int)me->query("combat_exp") < 650000 )
        return notify_fail("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
    if( me->query_int() < 38 )
        return notify_fail("����Ŀǰ��������������û�а취ѧ������ܡ�\n");
    cost = 40 * ( 1 + ( 38 - (int)me->query("int"))/20 );
    if (cost < 10) cost = 10; // minimum cost
    if( me->query_skill("jiuyin-baiguzhua", 1) < 140 )
        return notify_fail("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫���ˣ�û��ѧ���κζ�����\n");
    my_skill = me->query_skill("jiuyin-baiguzhua", 1);
    if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
        write("Ҳ����ȱ��ʵս���飬��Բ���������˵�Ķ��������޷���ᡣ\n");
    else write("���ж����йؾ����׹�צ�ļ��ɣ��ƺ���Щ�ĵá�\n");
    me->improve_skill("jiuyin-baiguzhua", ((int)me->query_skill("literate", 1)/5+1) );
    if (cost < 1) cost = 1;
    me->set_temp("last_damage_from", "�ж������书�������Ļ���");
    me->receive_damage("jing", cost );
if(me->query_skill("jiuyin-baiguzhua",1)<200)
    me->add("potential", - random(2));
    return 1;
}

int query_autoload()
{
        return 1;
}
