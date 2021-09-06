// enable.c

#include <ansi.h>

inherit F_CLEAN_UP;

mapping valid_types = ([
        "unarmed":      "ȭ��",
        "sword":        "����",
        "blade":        "����",
        "dagger":       "ذ��",
        "brush":        "�ʷ�",
        "spear":        "ǹ��",
        "hook":         "����",
        "stick":        "����",
        "staff":        "�ȷ�",
        "club" :        "����",
        "throwing":     "����",
        "force":        "�ڹ�",
        "parry":        "�м�",
        "dodge":        "�Ṧ",
        "whip":         "�޷�",
        "axe":          "����",
        "finger":       "ָ��",
        "hand":         "�ַ�",
        "cuff":         "ȭ��",
        "claw":         "צ��",
        "strike":       "�Ʒ�",
        "leg":          "�ȷ�",
        "hammer":       "����",
        "arrow":        "����",
]);

int main(object me, string arg)
{
        mapping map, skills;
        string *skill, ski, map_to;
        int i, modify, tmp;

        seteuid(getuid());

        skill = sort_array(keys(valid_types), (: strcmp :));
        skill = sort_array(skill, -1);
        if (arg && wizardp(me)) {
                object ob = present(arg, environment(me));

                if (!ob) ob = find_living(arg);
                if (!ob) ob = LOGIN_D->find_body(arg);
                if (ob) {
                        me = ob;
                        arg = 0;
                }
        }

        if( !arg ) {
                map = me->query_skill_map();
                if( !mapp(map) || sizeof(map)==0 )
                        return notify_fail("������û��ʹ���κ����⼼�ܡ�\n");

                write("��������Ŀǰʹ���е����⼼�ܡ�\n");
                i = sizeof(skill);
                while (i--){
                        if( undefinedp(valid_types[skill[i]]) ) {
                                map_delete(map, skill[i]);
                                continue;
                        }
                        if( !me->query_skill(skill[i]) ) continue;
                        modify = me->query_temp("apply/" + skill[i]);
                        write(sprintf("  %-20s�� %-20s  ��Ч�ȼ���%s%3d\n" NOR, 
                                valid_types[skill[i]] + " (" + skill[i] + ")",
                                undefinedp(map[skill[i]]) ? "��" : to_chinese(map[skill[i]]),
                                (modify==0 ? "" : (modify>0 ? HIC : HIR)),
                                me->query_skill(skill[i])));
                }
                return 1;
        }

        if( arg=="?" ) {
                write("�����ǿ���ʹ�����⼼�ܵ����ࣺ\n");
                skill = sort_array(keys(valid_types), (: strcmp :) );
                for(i=0; i<sizeof(skill); i++) {
                        write(sprintf("  %s (%s)\n", valid_types[skill[i]], skill[i] ));
                }
                return 1;
        }

        if(userp(me) 
        && (me->query_temp("no_enable") || me->is_busy() || me->is_perform() || me->is_exert())
        && arg)
                return notify_fail("�����ڲ��ܼ������⼼�ܡ�\n");
        if (arg == "all") {
                skills = me->query_skills();
                if (!skills) return notify_fail("��Ŀǰ��û��ѧ���κμ��ܡ�\n");
                i = sizeof(skill);
                while (i--) {
                        ski = skill[i];
                        modify = sizeof(skills);
                        tmp = 0;
                        while (modify--) {
                                if (SKILL_D(keys(skills)[modify])->valid_enable(ski)
                                && values(skills)[modify] > tmp) {
                                        map_to = keys(skills)[modify];
                                        tmp = values(skills)[modify];
                                }
                        }
                        if (tmp) {
                                me->force_me("enable " + ski + " " + map_to);
                        }
                }
                if (me->query_skill_mapped("force")) {
                        if ((tmp = (me->query_skill("force") / 2)) > 200)
                                tmp = 200;
                        me->force_me("enforce " + tmp);
                }
                write("����׼����ϡ�\n");
                return 1;
        }

        if (arg == "none") {
                skills = me->query_skill_map();
                if (!skills) return notify_fail("��Ŀǰ��û�м����κμ��ܡ�\n");
                skill = keys(skills);
                i = sizeof(skill);
                while (i--) {
                        if (skill[i] == "force") continue;
                        me->map_skill(skill[i]);
                        write("�����ʹ�û�����" + valid_types[skill[i]] + "��\n");
                }
                me->force_me("enforce none");
                me->force_me("prepare none");
                return 1;
        }

        if( sscanf(arg, "%s %s", ski, map_to)!=2 )
                return notify_fail("ָ���ʽ��enable|jifa [<��������> <��������>|none]\n");

        if( undefinedp(valid_types[ski]) )
                return notify_fail("û������������࣬�� enable ? ���Բ鿴����Щ���ࡣ\n");

        if( map_to=="none" ) {
                me->map_skill(ski);
                me->reset_action();
                write("�����ʹ�û�����" + valid_types[ski] + "��\n");
                return 1;
        } else if( map_to==ski ) {
                write("��" + to_chinese(ski) + "��������" + valid_types[ski] + "�Ļ���������Ҫ enable��\n");
                return 1;
        }

        if( !me->query_skill(map_to, 1))
                return notify_fail("�㲻�����ּ��ܡ�\n");

        if( !SKILL_D(map_to)->valid_enable(ski))
                return notify_fail("������ܲ��ܵ���������;��\n");

        if (me->query_skill_prepared(ski) && me->query_skill_prepared(ski) != map_to)
                return notify_fail(to_chinese(map_to) + "�������е���ϲ�����\n");

        write("�������" + to_chinese(map_to) +"��Ϊ���" + valid_types[ski] + "��\n");

        if (ski=="force" && map_to != me->query_skill_mapped(ski))
        {
                write("�������һ���ڹ��������������¶�����\n");
                me->set("neili", 0);
        }

        me->map_skill(ski, map_to);
        me->reset_action();
        
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : enable|jifa [<��������> <��������> | none]
           enable|jifa ?

���ָ������ָ����Ҫ�õļ��ܣ���ָ����������ͼ������ơ�������Ӳ�
�������ʾ���������༰��Ŀǰ��ʹ�õļ������ƣ������һ�������г���
����ʹ�����⼼�ܵļ������ࡣ
 
HELP
        );
        return 1;
}

