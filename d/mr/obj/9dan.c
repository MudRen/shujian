// 9dan.c
// by leontt@Sj 10/10/2000

#include <ansi.h>
inherit ITEM;
mapping *poi_list = ({
        (["id":         "snake_poison", // ���ж���E������
          "name":       "�߶�", // ���ж�����������
          "col":        "\"BLU\"", // �ж���������ɫ
          "con":        "տ��֮��",]), // �ж�������״̬
        (["id":         "lvbo_poison",
          "name":       "�̲���¶�涾",
          "col":        "\"BLU\"",
          "con":        "տ��֮��",]),
        (["id":         "xx_poison",
          "name":       "�����ƶ�",
          "col":        "\"BLU\"",
          "con":        "տ��֮��",]),
        (["id":         "dsy_poison",
          "name":       "���ڴ���ӡ�ƶ�",
          "col":        "\"CYN\"",
          "con":        "����",]),
        (["id":         "fs_poison",
          "name":       "��ʬ��",
          "col":        "\"HIG\"",
          "con":        "����",]), 
        (["id":         "huagu_poison",
          "name":       "�������ƾ綾",
          "col":        "\"BLU\"",
          "con":        "տ��֮��",]),
        (["id":         "man_poison",
          "name":       "�����ܻ���",
          "col":        "\"HIB\"",
          "con":        "����",]),
        (["id":         "qinghua_poison",
          "name":       "�黨��",
          "col":        "\"MAG\"",
          "con":        "����",]),
        (["id":         "qishang_poison",
          "name":       "����ȭ��",
          "col":        "\"HIR\"",
          "con":        "����֮��",]),
        (["id":         "yyz_hurt",
          "name":       "һ��ָ����",
          "col":        "\"HIY\"",
         "con":        "����֮ɫ",]),
        (["id":         "hunyuan_hurt",
          "name":       "��Ԫ�޼�����",
          "col":        "\"HIR\"",
         "con":        "����֮��",]),
        (["id":         "qzhu_poison",
          "name":       "ǧ�����ֶ�",
          "col":        "\"HIR\"",
          "con":        "����֮��",]),
        (["id":         "sld_shexin",
          "name":       "���Ĵ�",
          "col":        "\"HIC\"", 
          "con":        "���״̬",]),
        (["id":         "sl_poison",
          "name":       "������",
          "col":        "\"BLU\"", 
          "con":        "տ��֮��",]),
        (["id":         "sy_poison",
          "name":       "����ӡ�ƶ�",
          "col":        "\"HIR\"",
          "con":        "����֮��",]),
        (["id":         "warm_poison",
          "name":       "�ȶ�",
          "col":        "\"RED\"",
          "con":        "���֮��",]),
        (["id":         "hot_poison",
          "name":       "��",
          "col":        "\"HIR\"",
          "con":        "����֮��",]),
        (["id":         "cold_poison",
          "name":       "����",
          "col":        "\"HIC\"",
          "con":        "����֮��",]),
        (["id":         "bing_poison",
          "name":       "�������붾",
          "col":        "\"HIB\"",
          "con":        "տ��֮��",]),
        (["id":         "bt_poison",
          "name":       "���߶�", 
          "col":        "\"YEL\"",
          "con":        "����֮��",]),
        (["id":         "hb_poison",
          "name":       "�������ƶ�",
          "col":        "\"HIB\"",
          "con":        "տ��֮��",]),
        (["id":         "tz_poison",
          "name":       "�����涾",
          "col":        "\"HIR\"",
          "con":        "����֮ɫ",]),
        (["id":         "cold_poison",
          "name":       "�������ƶ�",
          "col":        "\"HIY\"",
          "con":        "����",]),
});

void setup()
{}
void init()
{
        add_action("do_eat", "fu");
}
void create()
{
        set_name(HIY"�����ת��"NOR, ({"huizhuan dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��Ľ���洫�ط����Ƶľ����ת������˵�ܽ�ٶ���\n");
//                set("value", 15); 
                set("no_give",1);
        }
        setup();
}

int do_eat(string arg)
{
        object me = this_player();
        int poi_lvl, neili_cost, i;
        mapping poi;

        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");

        if((int)me->query_skill("medicine", 1) < 80 )
                return notify_fail("��ı�������̫�ͣ�����Ҳû����á�\n");

        if (me->query("family/family_name") != "����Ľ��")
                return notify_fail("�㲢����Ľ�ݵ��ӣ�͵�Ա��˵Ķ���������ô!?\n");
        if( me->is_fighting() )
                return notify_fail("������ս���У��޷��ƶ���\n");

        if( me->is_busy() )
                return notify_fail("����æ���أ��޷��ƶ���\n"); 

        for(i=0;i<sizeof(poi_list);i++)
        {
                poi = poi_list[i];
                if (me->query_condition(poi["id"]) > 0 )
                {
                        poi_lvl = me->query_condition(poi["id"]);
                        neili_cost = poi_lvl*3;
                        if (poi_lvl < (int)me->query_skill("medicine", 1)*2)
                        {
                                if( (int)me->query("neili") < neili_cost )
                                        return notify_fail("������������Խ���"HIY"�����ת��"NOR"ȥ�������඾��\n");
                                 message_vision("$N˫�۽����˹��ƶ�������"HIY"�����ת��"NOR"����Ч���������ϵ�" + poi["con"] + "�𽥼��ˡ�\n",me);
                                tell_object(me,"�����е�" + poi["name"] + "�Ѿ���ȫȥ����\n");
                                me->clear_condition(poi["id"]);
                                me->add("neili",-neili_cost);
                                me->start_busy(2);
                                me->set_temp("mr/9dan",1);
                                me->apply_condition("medicine",5 + random(5));
                                call_out("dest",0,this_object());
                                break;
                        }
                        else 
                        {
                                me->apply_condition(poi["id"],poi_lvl-(int)me->query_skill("medicine", 1)*2);
                                 message_vision("$N˫�۽����˹��ƶ�������"HIY"�����ת��"NOR"����Ч���������ϵ�" + poi["con"] + "�𽥼��ˡ�\n",me);
                                tell_object(me,"������" + poi["name"] + "�Ѿ��������ˡ�\n");
                                me->add("neili",-neili_cost);
                                me->start_busy(2);
                                me->set_temp("mr/9dan",1);
                                me->apply_condition("medicine",5 + random(5));
                                call_out("dest",0,this_object());
                                break;
                        }
                }
        }

        if (me->query_temp("mr/9dan")<1)
                return notify_fail("��û���ж���\n");
        me->delete_temp("mr/9dan");
        me->delete_temp("mr/get_9dan");
        return 1;
}

void dest(object ob)
{ 
        destruct(ob);
        return;
}
