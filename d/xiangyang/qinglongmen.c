// /d/xiangyang/qinglongmen.c

#include <ansi.h>
inherit ROOM;
string look_gaoshi();

void create()
{
        set("short", YEL"������"NOR);
        set("long", @LONG
�����Ǿ������������ǵĶ��ţ���ʱ���ж�����׵�ʿ��������ȥ����
���߿��Խ��밲�ա����վ��ڡ����ŵ�ǽ��������һֽ��ʾ(gaoshi)��
LONG
        );
        set("outdoors", "����");
        set("xyjob", 1);
        set("item_desc", ([
                "gaoshi" : (:look_gaoshi:),
        ]));

        set("exits", ([
                "east" : "/d/xiangyang/outeroad1",
                "west" : "/d/xiangyang/eroad1",
        ]));

        set("objects", ([
                NPC_D("guanfu/wujiang") : 1,
                NPC_D("guanfu/bing") : 2,
        ]));

	set("incity",1);
	setup();
}

string look_gaoshi()
{
        return FINGER_D->get_killer() + "\n��������ʹ\n���ĵ�\n";
}

void init()
{
    object me = this_player();
    object ob;

    if(!me->query("quest/hsjf/fy5")
      ||!me->query("quest/hsjf/fy5/meet_killers")
      ||me->query("quest/hsjf/fy5/location")!="qlmnj"
      ||me->query("quest/hsjf/fy5/yanlian")!="pass"
      ||me->query("quest/hsjf/fy5/kill_killer_pass")
      ||me->query("quest/hsjf/fy5/exp")+100000>(int)me->query("combat_exp")
      ||me->query("quest/hsjf/fy5/time")+43200>time())
        return;

    me->start_busy(5);//����Quest,��ֹplayer�����߶�. by lsxk@hsbbs /2007/9/1
    call_out("fengyi5_killer",2,me);
    ob = new("/d/huashan/npc/fy5_npc_target");
    ob->set("escape_id",me->query("id"));
    ob->move(environment(me));
    return;
}

int fengyi5_killer(object me)
{
    object ob;

    message_vision(HIY"$N�ߵ�����,����һ������֮�˶�ݺݵض���һλ����ģ������!\n"
                     +"ֻ����λ���������ĵ���������������ӿ���ҪΪ������ĸ����\n"
                     +"�İ�,�������,�������ζԵ���һ����Т����?��\n\n"
                  +HIW"����������֮�˵�:�����ӹ���Т���ǲ�Т���ԹԵİ�Ǯ��������\n"
                  +HIW"��ү�Ҿ�����һ����Ҫ��Ȼ���ߺߡ�����\n\n"
                  +HIC"���������ɽ�������Ǯ��������ȴ�Գ���һ˿�־塣ֻ��������\n"
                  +HIC"֮��������ǰ�������ᣬ�㵱������֮��������һ�������󵨣�\n"
                  +HIC"���컯��֮�£���Ȼ�������٣�����û�������ˣ���\n\n"
                  +HIM"������֮�˵���$Nһ�۵��������������Ӿ������������ٹ����£�\n"
                  +HIM"Ҫ��Ȼ����ÿ�����\n\n"
                  +HIR"$N�ѷ�ŭ֮������������һ����Х����������ˣ��㵹�ǸҶ���\n"
                  +HIR"һ�����������°ڳ��˶������ƣ�\n\n"
                  +HIG"������֮�ˣ���Ȼ�ѱ���ŭ���ȵ�������Ȼ��ô���������Ҿͳ�\n"
                  +HIG"ȫ�㣡��˵�գ������������㶷����һ��\n"NOR,me);

    me->set("quest/hsjf/fy5/time",time());
    me->set("quest/hsjf/fy5/exp",(int)me->query("combat_exp"));
    ob = new("/d/huashan/npc/fy5_npc");
    ob->move(environment(me));
    me->apply_condition("fy5_killers",15);
    log_file("quest/fengyi5", sprintf(HIM"�з�����5Quest��¼��%s(%s)��ʼ"HIW"��ս"HIM"������ˡ�����%d��"NOR, me->name(1),me->query("id"),me->query("combat_exp")) );
    return 1;
}
