inherit F_DBASE;

#include <ansi.h>
#include <net/daemons.h>
#include <net/macros.h>

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	mapping mud_list;
	mixed *muds;
	string output;
	int loop, size, count=0, total, n=0;

	if (!find_object(DNS_MASTER)) {
		write("��·���鲢û�б����롣\n");
		return 1;
	}

	//      Obtain mapping containing mud data
	mud_list = (mapping)DNS_MASTER->query_muds();

	if(!mud_list){
		write(MUD_NAME + "Ŀǰ��û�и���·������ Mud ȡ����ϵ��\n");
		return 1;
	}

	//      Get list of all mud names within name server
	muds = keys( mud_list ) - ({ "DEFAULT" });

	//      Place mudlist into alphabetical format
	muds = sort_array(muds, 1);

	//      If mudname provided, search server's database for a match
	//      and display its cooresponding address
	if (arg)
		arg = upper_case(arg);
	if (arg && arg != "ALL") {
		arg = htonn(arg);
		if(!mapp( mud_list[arg] )) {
			write(MUD_NAME + "��û�к���� Mud ȡ����ϵ��\n");
			return 1;
		}
		if (wizardp(me) && !me->query("env/debug"))
			write(sprintf("�й� %s ����Ѷ��\n%O\n", arg, mud_list[arg]));
		else
			write(sprintf("\n�й� %s �����ϣ�\n"
				"������������������������������������������\n"
				"�������ƣ�  %s\n"
				"���ԣ�      %s\n"
				"�汾��      %s\n"
				"MudOS��     %s\n"
				"Mudlib��    %s\n"
				"������      %s\n"
				"�˿ڣ�      %s\n"
				"״̬��      %s\n"
				"������ң�  %s\n"
				"����ʱ�䣺  %s\n"
				"��������������������������������������������\n\n",
				mud_list[arg]["NAME"],
				undefinedp(mud_list[arg]["MUDNAME"])?
				"����":mud_list[arg]["MUDNAME"],
				undefinedp(mud_list[arg]["ENCODING"])?
				"����":(mud_list[arg]["ENCODING"]=="GB"?"���庺��":"���庺��"),
				undefinedp(mud_list[arg]["VERSION"])?
				"����":mud_list[arg]["VERSION"],
				undefinedp(mud_list[arg]["DRIVER"])?
				"����":mud_list[arg]["DRIVER"],
				undefinedp(mud_list[arg]["MUDLIB"])?
				"����":mud_list[arg]["MUDLIB"],
//                         mud_list[muds[loop]]["HOSTADDRESS"],
                           "localhost", 
				mud_list[arg]["PORT"],
				mud_list[arg]["_dns_no_contact"]<1?
				"����":"�Ͽ�",
				undefinedp(mud_list[arg]["USERS"])?
				"����":mud_list[arg]["USERS"],
				undefinedp(mud_list[arg]["TIME"])?
				"����":CHINESE_D->chinese_time(atoi(mud_list[arg]["TIME"])/600*600)
			));
		return 1;
	}

        output = "\n      ��  ��  ��  ��       �� �� �� ַ           �˿�         ��  ��  ʱ  ��      ����\n";
	output += repeat_string("��", 43) + "\n";
	//      Loop through mud list and store one by one
	for(loop = 0, size = sizeof(muds); loop<size; loop++) {
		if (!arg && mud_list[muds[loop]]["VERSION"] != MUDLIB_VERSION)
			continue;

		if (arg) {
			if (arg !="ALL" && mud_list[muds[loop]]["MUDLIB"] != MUDLIB_NAME )
				continue;
		}

		if (mud_list[muds[loop]]["_dns_no_contact"] > 0) {
			if( !me || !wizardp(me) || (wizardp(me) && me->query("env/debug")) )
				continue;
		}

		if (mud_list[muds[loop]]["TIME"] != query(muds[loop])) {
			set(muds[loop], mud_list[muds[loop]]["TIME"]);
			set(muds[loop]+".Time", time());
		}

		if (htonn(upper_case(muds[loop])) == htonn(upper_case(INTERMUD_MUD_NAME)))
			output +=  BRED+HIY;

             output += sprintf("%-13s%9s %-15s%6s\n",
			(undefinedp(mud_list[muds[loop]]["MUDNAME"])?"":mud_list[muds[loop]]["MUDNAME"]),
                        "(New-SJ)",
                  "wt.sjmud.cn  (��ͨ)  ",
                   "5555/6666",
			
		);
             output += sprintf("%-13s%9s %-15s%6s",
			"             ",
                        "          ",
                  "  dx.sjmud.cn  (����)  ",
                        "8888/110 ",
		);

		if (time() > query(muds[loop]+".Time") + 130)
			output += "<ʧȥ��ϵ"+CHINESE_D->chinese_time((time()-query(muds[loop]+".Time"))/60*60)+">";
		else {
			total = atoi(mud_list[muds[loop]]["TIME"]);
                        output += sprintf("%21s", CHINESE_D->chinese_time(total/60*60));
			if(!undefinedp(mud_list[muds[loop]]["USERS"])) {
                                output+=sprintf("%7d", sizeof(children(USER_OB))-1 );
                                count += sizeof(children(USER_OB))-1;
			} else output+=" ----";
		}
		n++;
		output += NOR"\n";
	}
	//      Display dumped mudlist output through user's more pager
	output += repeat_string("��", 43) + "\n";
	output += "���齣������" + chinese_number(count) + "λ�����" + chinese_number(n) + "��վ�������С�\n";
	write(output);

	return 1;
}

int help()
{
	write("
ָ���ʽ��mudlist		�г������е�"MUD_NAME"վ�㡣
	  mudlist <MudName>	�г�ָ�� Mud ����Ϣ��
	  mudlist all		�г�Ŀǰ���������е� Mud��
"	);
	return 1;
}
