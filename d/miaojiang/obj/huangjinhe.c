
inherit ITEM;

void create()
{
        set_name("�ƽ��",({ "huangjin he", "he" }) );
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
              set("unit", "ֻ");
              set("material", "steel");
              set("treasure",1);
              set("long", "һֻ�ɻƽ�����С���ӣ�����װ����ֻ���룬�ƺ���������������а�ɹ�����á�\n");
              set("value", 500);
              set("skill", ([
                        "name": "poison",
                        "exp_required": 1000,
                        "jing_cost": 20,
                        "jingli_cost": 20,
                        "neili_cost": 30,
                        "qi_cost": 30,
                        "difficulty": 10,
                        "max_skill": 200,
                ]) );
        }
}

void init()
{
        if( this_player() == environment() )
                add_action("do_suck", "suck");
}

int do_suck(string arg)
{
        object me = this_player();

        if ( arg != "blood" || !living(this_player()))
        return notify_fail("��Ҫ��ʲô��\n");

        if( this_player()->is_busy() )
                return notify_fail("����һ��������û�����, �����˹�������\n");
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("ǧ�����ֱ��������ϰ��\n");
        if ((int)me->query_skill("poison", 1) < 120)
        return notify_fail("�㶾��������ѧ����ǧ�����֡�\n");
        if ((int)me->query_skill("qianzhu-wandushou", 1) < 31)
        return notify_fail("��ǧ�����ֵĻ����������޷�������ߡ�\n");
         if ((int)me->query("max_neili") < 1000)
        return notify_fail("����������̫��, �ֿ����˶��ʡ�\n");
        if ( me->is_fighting())
        return notify_fail("����ս���в����˹�������\n");

   

        if ((int)me->query_skill("poison", 1) <= 200 )
          {
              me->receive_damage("jing", 20);
              me->receive_damage("jingli", 20);
              me->receive_damage("qi", 25);
              me->add("neili", -30);
         

              message_vision("$N����ׯ������֮�ݣ���������ָ������У�����Ļ���������
����ҧס��$N��ʳָ��$N�������������������������Ǳ������
���붾�򿹡�ͬʱü�ĺ����Ե�̫��Ѩ������������һ�������
$N��ҧ���أ���������ʹ�ࡣ�������ã����������۾�������
�������ˣ�����Ѫɫ��һ�������˳�������Χ������һ�����㡣\n", me);
              switch(random(2)) {
                     case 0:
                       me->improve_skill("poison", (int)(me->query("int") / 5));
                       write ("���������������еĶ��ʻ������뵤�ֻ������һ����\n" "��Ի�������������ּ�����һЩ! \n");
                       break;
                      case 1:
                       me->improve_skill("chousui-zhang", (int)(me->query("int") / 2));
                       write ("�㼱����ת��ָ��Ѫ�������Ż������ڵĶ�Һ�������Լ�Ѫ�С�\n" "���ǧ�����ֵ�����ּ�����һ��! \n");
                       break;
                     }
              return 1;
           }

           return 0;
}

