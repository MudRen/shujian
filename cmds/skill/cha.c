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
        object ob;
        mapping skl, lrn, map;
        string *sname, *mapped;
        int i, j;

        seteuid(getuid());

        if(!arg)
                ob = me;
        else{
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
        if (!ob) ob = LOGIN_D->find_body(arg);
                if (!ob || !me->visible(ob)) return notify_fail("��Ҫ�쿴˭�ļ��ܣ�\n");
        }

        if( ob!=me && !wizardp(me) ){
        	if(environment(ob)!=environment(me))
        		return notify_fail("��Ҫ�쿴˭�ļ��ܣ�\n");
        	if(!ob->is_apprentice_of(me)
        	&& !me->is_apprentice_of(ob) 
        	&& ob->query("winner") != me->query("id")
        	&& me->query("marry/id") != ob->query("id"))
                	return notify_fail("ֻ����ʦ����ʦͽ��ϵ�����ܲ쿴���˵ļ��ܡ�\n");
	}
	
        skl = ob->query_skills();
        if(!j = sizeof(skl)) {
                write( (ob==me ? "��" : ob->name(1)) + "Ŀǰ��û��ѧ���κμ��ܡ�\n");
                return 1;
        }
        write( (ob==me ? "��" : ob->name(1)) +"Ŀǰѧ��"+chinese_number(j)+"�ּ��ܣ�\n");
        sname  = sort_array( keys(skl), (: strcmp :) );
        
        map = ob->query_skill_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});

        lrn = ob->query_learned();
        if( !mapp(lrn) ) lrn = ([]);
        
        for(i=0; i < j; i++) 
        if (strlen(strip(to_chinese(sname[i]), " (" + sname[i] + ")")) > 17) {
        	write(sprintf("%s%s%-18s%-22s" NOR " - %s %3d/%6d\n",
                        (lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
                        (member_array(sname[i], mapped)==-1? "  ": "��"),
                        to_chinese(sname[i]), " (" + sname[i] + ")",
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                      skl[sname[i]], (int)lrn[sname[i]],));}
                      else {
          write(sprintf("%s%s%-12s%-28s" NOR " - %s %3d/%6d\n",
                        (lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
                        (member_array(sname[i], mapped)==-1? "  ": "��"),
                        to_chinese(sname[i]), " (" + sname[i] + ")",
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]],
        	));
        }
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
                	//grade = level / 7; this is old SJ system
                	// but now system the player combat speed is very fast.
                        grade = level / 17;
                        if( grade >= sizeof(skill_level_desc) )
                                grade = sizeof(skill_level_desc)-1;
                        return skill_level_desc[grade];
        }
}

int help(object me)
{
        string str = "\n";
        int i = sizeof(skill_level_desc);

        while(i--) {
                str = "    " + skill_level_desc[i] + str;
                if (i % 5 == 0) str = "\n" + str;
        }
        write(@HELP
ָ���ʽ : cha [<ĳ��>]

���ָ����������ѯ��ѧ���ļ��ܡ�
��Ҳ����ָ��һ��������ʦͽ��ϵ�Ķ����� skills ���Բ�֪�Է��ļ���״����
��ʦ���Բ�ѯ�κ��˻� NPC �ļ���״����
���ܵ������ɵ͵�������Ϊ��
HELP);
        write(str);
    return 1;
}
