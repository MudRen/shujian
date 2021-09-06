// skills.c

#include <ansi.h>
#include <level.h>

inherit F_CLEAN_UP;

string *skill_level_desc = ({ LEVEL });

string *knowledge_level_desc = ({
	BLU "��ѧէ��" NOR,HIB "�����ž�" NOR,MAG "��֪һ��" NOR,HIM "��������" NOR,
	CYN "������" NOR,YEL "����С��" NOR,YEL "�ڻ��ͨ" NOR,HIY "�������" NOR,
	HIY "��Ȼ���" NOR,HIG "���д��" NOR,HIG "��ͬ����" NOR,HIC "������˫" NOR,
	HIC "������" NOR,HIW "�����ױ�" NOR,HIW "������ʥ" NOR,HIR "��ǰ����" NOR
});


string skill_level(string, int);

int main(object me, string arg)
{
        object ob, man, *all;
        mapping fam, skl, lrn, map;
        string *sname, *mapped;
        int sp, dp;
        int i, cost;

        seteuid(getuid());

    	if (me->is_busy()) return notify_fail("����æ���ء�\n");
    	
        all = all_inventory(environment(me));
        for(i=0; i<sizeof(all); i++) {
        	if( living(all[i]) && !userp(all[i]) && all[i]->query("can_speak") && !all[i]->query("mute")) 
        		man = all[i];
        }

        if ( (!(fam = me->query("family")) || fam["family_name"] != "ؤ��") )
                return notify_fail("ֻ����ؤ���ܴ�̽���˵ļ��ܣ�\n");

        if ( !objectp(man) )
                return notify_fail("��Χû���ܰ���ȥ�˽���˵ļ��ܣ�\n");

        if ( me->query_skill("checking",1) < 10 )
                return notify_fail("��Ĵ�̽������δ���죬�޷��˽���˵ļ��ܣ�\n");

        if ( !arg )
                return notify_fail("��Ҫ����˭�ļ��ܣ�\n");

        if ( present(arg, environment(me)) )
                return notify_fail("��Ҫ�������˾��ڱ��ϣ��������ʲ����׵��ɣ�\n");

        ob = find_player(arg);
        if (!ob) ob = find_living(arg);
        if (!ob || !me->visible(ob)) return notify_fail("��Ҫ����˭�ļ��ܣ�\n");

        if ( ob == me )
                return notify_fail("��û��ô���ɣ�Ҫ���˸������Լ��ļ��ܣ�\n");

        cost = me->query("max_jing")/(me->query_skill("checking",1)/10) - 10;

        if ( me->query("jing") <= cost )
                return notify_fail("������̫���ˣ��޷�ȥ�������˵ļ��ܡ�\n");

        tell_object(me, "������ǰȥ��С���������" + man->name(1) + "��������" + ob->name() + "����� ...\n\n");
        message("vision", "ֻ��" + me->name() + "����Ц����" + man->name() + "˵�Ż��������ڴ���Щʲô��\n\n", 
                environment(me), ({ me, man }) );
        me->start_busy(1+random(2));

        sp = me->query_skill("checking")*10 + me->query("kar")*5 + me->query("jing") + man->query("jing");
        dp = ob->query("kar")*5 + ob->query("jing")*2;
        
        if (ob->query("no_quest") || random(sp) < random(dp))
                return notify_fail( man->name() + "ҡ��ҡͷ��˵���������ҿɲ������"
                        + RANK_D->query_respect(me) + "����ȥ����˴���һ�°ɣ�\n");

        me->receive_damage("jing", cost );
	if (ob->query("env/check") == 314) ob->add("env/check_"+me->query("id"), 1);
        skl = ob->query_skills();
        if(!sizeof(skl)) {
                write( man->name() + "�����㣺 " + ob->name(1) + "Ŀǰ��û��ѧ���κμ��ܡ�\n");
                return 1;
        }
        write( man->name() + "�����㣺 " + ob->name(1) +"Ŀǰ��ѧ���ļ��ܣ�\n\n");
        sname  = sort_array( keys(skl), (: strcmp :) );
        
        map = ob->query_skill_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});

        lrn = ob->query_learned();
        if( !mapp(lrn) ) lrn = ([]);
        
        i = random(sizeof(skl));

        write(sprintf("%s%s%-12s%-28s" NOR " - %s %3d/%6d\n",
                (lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
                (member_array(sname[i], mapped)==-1? "  ": "��"),
                to_chinese(sname[i]), " (" + sname[i] + ")",
                skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                skl[sname[i]], (int)lrn[sname[i]],
        ));
        if (random((int)me->query_skill("checking",1))>100){
         	me->add("combat_exp", 1 + random(4));
         	me->add("potential", random(2));
        }
        
        write("\n");
        return 1;
}

string skill_level(string type, int level)
{
        int grade;

        switch(type) {
                case "knowledge":
			grade = level / 20;
                        if( grade >= sizeof(knowledge_level_desc) )
                                grade = sizeof(knowledge_level_desc)-1;
                        return knowledge_level_desc[grade];
                default:
			grade = level / 7;
                        if( grade >= sizeof(skill_level_desc) )
                                grade = sizeof(skill_level_desc)-1;
                        return skill_level_desc[grade];
        }
}

int help(object me)
{
        write(@HELP
ָ���ʽ : check|dating [<ĳ��>]

���ָ������������������ѧ���ļ��ܡ�

��Ҳ����ָ��һ��������ʦͽ��ϵ�Ķ����� skills|cha ���Բ�֪�Է��ļ���״����

������Ϊؤ�����ר�ã�����ѧϰ��Ӧ�ļ��ܡ�

HELP
    );
    return 1;
}
