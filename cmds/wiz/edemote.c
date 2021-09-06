// edemote.c
// Modified by Numa 1999-11-18 can edit emote by line 

inherit F_CLEAN_UP;

string *line = ({
	"myself",
	"others",
	"myself_self",
	"others_self",
	"myself_target",
	"target",
	"others_target",
});

string *line_info = ({
	"��ָ������ʹ����� emote ʱ�����Լ�������ѶϢ��\n",
	"��ָ������ʹ����� emote ʱ�������˿�����ѶϢ��\n",
	"���Լ�ʹ����� emote ʱ���Լ�������ѶϢ��\n",
	"���Լ�ʹ����� emote ʱ�������˿�����ѶϢ��\n",
	"�Ա���ʹ����� emote ʱ���Լ�������ѶϢ��\n",
	"�Ա���ʹ����� emote ʱ��ʹ�ö��󿴵���ѶϢ��\n",
	"�Ա���ʹ����� emote ʱ�������Լ���ʹ�ö����⣬�����˿�����ѶϢ��\n",
});

int main(object me, string arg)
{
        mapping emote;
        mapping tmp;
        string newemote, place;
        int i, j, k, get=0;

        if( !arg ) return notify_fail("��Ҫ�༭ʲô emote��\n");

        if( sscanf(arg, "-c %s %s", arg, newemote) ) {
                write("���� emote��" + arg + "\n");
                EMOTE_D->set_emote(newemote, EMOTE_D->query_emote(arg));
                return 1;
        }

        if( sscanf(arg, "-d %s", arg) ) {
                write("ɾ�� emote��" + arg + "\n");
                EMOTE_D->delete_emote(arg);
                return 1;
        }

        if( sscanf(arg, "-p %s", arg) ) {
                emote = EMOTE_D->query_emote(arg);
                printf("�ϴ��޸ģ�%s\n", emote["updated"]);
                printf("��������������������������\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
                        emote["myself"], emote["others"], emote["myself_self"],
                        emote["others_self"], emote["myself_target"], emote["target"],
                        emote["others_target"] );
                return 1;
        }
// Here add by Numa for edemote can select line.
	if( sscanf(arg, "-%d %s", i, arg) )
	{
                tmp = EMOTE_D->query_emote(arg);
                emote = (["updated":geteuid(me)]);
		for (j=0;j<7;j++)
                {
                	if (i == j+1)
                	{
                		get = 1;
                		for (k=0;k<7;k++)
                		{
                			emote[line[k]] = tmp[line[k]];
                		}
	                	place = line[j];
        	        	write("�༭ emote��" + arg + "�ĵ�"+CHINESE_D->chinese_number(i)+"�У�\n");
                		write("������������������������������������������������������������������������\n");
        			write(line_info[j] + tmp[place] + "->");
                		input_to("get_msg_select", place, emote, tmp, arg);
                		return 1;
                	}
                }
                
                if (get == 0)
                	write("��Ҫ�༭ emote ("+arg+")�ĵڼ��У�\n");
                return 1;
        }
// End
        tmp = EMOTE_D->query_emote(arg);
        emote = (["updated":geteuid(me)]);

        write("�༭ emote��" + arg + "\n");
        write("ѶϢ�����кü��У��� . ��ʾ������\n");
        write("ѶϢ�п�ʹ�õĲ��������¼��֣�\n");
        write("  $N  �Լ������֡�\n");
        write("  $n  ʹ�ö�������֡�\n");
        write("  $P  �Լ����˳ƴ����ʣ����㡢������������\n");
        write("  $p  ʹ�ö�����˳ƴ����ʣ����㡢������������\n");
        write("  $S  ���Լ��ĳƺ���\n");
        write("  $s  ���Լ��Ĵ�³�ƺ���\n");
        write("  $C  ���Լ����سơ�\n");
        write("  $c  �Ա��˵��سơ�\n");
        write("  $R  �Ա��˵���ơ�\n");
        write("  $r  �Ա��˵Ĵ�³�ƺ���\n");
        write("������������������������������������������������������������������������\n");
        write("��ָ������ʹ����� emote ʱ�����Լ�������ѶϢ��\n" + tmp["myself"] + "->");
        input_to("get_msg_myself", emote, tmp, arg);
        return 1;
}

int get_msg_select(string msg, string place, mapping emote, mapping tmp, string pattern)
{
        if (msg=="" && undefinedp(emote[place])) {
                emote[place] = tmp[place];
                msg=".";
        }
        if (msg==".") {
                EMOTE_D->set_emote(pattern, emote);
                write("Emote �༭��ϡ�\n");
                return 1;
        }
        emote[place] = msg + "\n";
        write("->");
        input_to("get_msg_select", place, emote, tmp, pattern);
        return 1;
}

int get_msg_myself(string msg, mapping emote, mapping tmp, string pattern)
{
        if (msg=="" && undefinedp(emote["myself"])) {
                emote["myself"] = tmp["myself"];
                msg=".";
        }
        if (msg==".") {
                write("��ָ������ʹ����� emote ʱ�������˿�����ѶϢ��\n" + tmp["others"] + "->");
                input_to("get_msg_others", emote, tmp, pattern);
                return 1;
        }
        if( !undefinedp(emote["myself"]) )
                emote["myself"] += msg + "\n";
        else emote["myself"] = msg + "\n";
        write("->");
        input_to("get_msg_myself", emote, tmp, pattern);
        return 1;
}

int get_msg_others(string msg, mapping emote, mapping tmp, string pattern)
{
        if (msg=="" && undefinedp(emote["others"])) {
                emote["others"] = tmp["others"];
                msg=".";
        }
        if (msg==".") {
                write("���Լ�ʹ����� emote ʱ���Լ�������ѶϢ��\n" + tmp["myself_self"] + "->");
                input_to("get_msg_myself_self", emote, tmp, pattern);
                return 1;
        }
        if( !undefinedp(emote["others"]) )
                emote["others"] += msg + "\n";
        else emote["others"] = msg + "\n";
        write("->");
        input_to("get_msg_others", emote, tmp, pattern);
        return 1;
}

int get_msg_myself_self(string msg, mapping emote, mapping tmp, string pattern)
{
        if (msg=="" && undefinedp(emote["myself_self"])) {
                emote["myself_self"] = tmp["myself_self"];
                msg=".";
        }
        if (msg==".") {
                write("���Լ�ʹ����� emote ʱ�������˿�����ѶϢ��\n" + tmp["others_self"] + "->");
                input_to("get_msg_others_self", emote, tmp, pattern);
                return 1;
        }
        if( !undefinedp(emote["myself_self"]) )
                emote["myself_self"] += msg + "\n";
        else emote["myself_self"] = msg + "\n";
        write("->");
        input_to("get_msg_myself_self", emote, tmp, pattern);
        return 1;
}

int get_msg_others_self(string msg, mapping emote, mapping tmp, string pattern)
{
        if (msg=="" && undefinedp(emote["others_self"])) {
                emote["others_self"] = tmp["others_self"];
                msg=".";
        }
        if (msg==".") {
                write("�Ա���ʹ����� emote ʱ���Լ�������ѶϢ��\n" + tmp["myself_target"] + "->");
                input_to("get_msg_myself_target", emote, tmp, pattern);
                return 1;
        }
        if( !undefinedp(emote["others_self"]) )
                emote["others_self"] += msg + "\n";
        else emote["others_self"] = msg + "\n";
        write("->");
        input_to("get_msg_others_self", emote, tmp, pattern);
        return 1;
}

int get_msg_myself_target(string msg, mapping emote, mapping tmp, string pattern)
{
        if (msg=="" && undefinedp(emote["myself_target"])) {
                emote["myself_target"] = tmp["myself_target"];
                msg=".";
        }
        if (msg==".") {
                write("�Ա���ʹ����� emote ʱ��ʹ�ö��󿴵���ѶϢ��\n" + tmp["target"] + "->");
                input_to("get_msg_target", emote, tmp, pattern);
                return 1;
        }
        if( !undefinedp(emote["myself_target"]) )
                emote["myself_target"] += msg + "\n";
        else emote["myself_target"] = msg + "\n";
        write("->");
        input_to("get_msg_myself_target", emote, tmp, pattern);
        return 1;
}

int get_msg_target(string msg, mapping emote, mapping tmp, string pattern)
{
        if (msg=="" && undefinedp(emote["target"])) {
                emote["target"] = tmp["target"];
                msg=".";
        }
        if (msg==".") {
                write("�Ա���ʹ����� emote ʱ�������Լ���ʹ�ö����⣬�����˿�����ѶϢ��\n" + tmp["others_target"] + "->");
                input_to("get_msg_others_target", emote, tmp, pattern);
                return 1;
        }
        if( !undefinedp(emote["target"]) )
                emote["target"] += msg + "\n";
        else emote["target"] = msg + "\n";
        write("->");
        input_to("get_msg_target", emote, tmp, pattern);
        return 1;
}

int get_msg_others_target(string msg, mapping emote, mapping tmp, string pattern)
{
        if (msg=="" && undefinedp(emote["others_target"])) {
                emote["others_target"] = tmp["others_target"];
                msg=".";
        }
        if (msg==".") {
                EMOTE_D->set_emote(pattern, emote);
                write("Emote �༭������\n");
                return 1;
        }
        if( !undefinedp(emote["others_target"]) )
                emote["others_target"] += msg + "\n";
        else emote["others_target"] = msg + "\n";
        write("->");
        input_to("get_msg_others_target", emote, tmp, pattern);
        return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : edemote [-c|-d|-p|-����] <emote>
 
���ָ������޸ģ�ɾ�� emote ���г������ݡ����� -d ������ɾ��
ָ���� emote��-p ��������г�ָ�� emote ������(�г���˳�����
�� emote ʱ��ͬ)��-���� ��������Ա༭ָ�� emote ��ָ����(��Χ
�Ǵ�1->7)��
 
���� emote ѶϢʱ��������Ŀ: û��Ŀ��, ָ��Ŀ����Ƕ��Լ�. ��
������ĳ��ѶϢ, ��ֱ���ڿհ������� '.' ����.
 
һ�� emote ѶϢ�����кܶ���, �ڿհ������� '.' ����������� emote.
 
�༭ emote ʱ���������µķ�������ʾ:
 
$N : �Լ�������.
$n : Ŀ�������.
$P : �Լ����˳ƴ�����.
$p : Ŀ����˳ƴ�����.
$S : ���Լ��ĳƺ���
$s : ���Լ��Ĵ�³�ƺ���
$C : ���Լ����سơ�
$c : �Ա��˵��سơ�
$R : �Ա��˵���ơ�
$r : �Ա��˵Ĵ�³�ƺ���
HELP
    );
    return 1;
}
