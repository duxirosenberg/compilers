// Generated from /home/drosenberg/University/UPC Exchange Semester/CL-lab/practica/asl/Asl.g4 by ANTLR 4.9.2
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class AslLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.9.2", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, ASSIGN=4, PLUS=5, SUB=6, MUL=7, DIV=8, MOD=9, 
		VAR=10, ARRAY=11, INT=12, FLOAT=13, CHAR=14, BOOL=15, EQ=16, NEQ=17, G=18, 
		GE=19, L=20, LE=21, AND=22, NOT=23, OR=24, IF=25, THEN=26, ELSE=27, ENDIF=28, 
		FUNC=29, ENDFUNC=30, READ=31, WRITE=32, WHILE=33, DO=34, ENDWHILE=35, 
		RETURN=36, LPAR=37, RPAR=38, SEMICOLON=39, COLON=40, COMMA=41, INTVAL=42, 
		FLOATVAL=43, BOOLVAL=44, CHARVAL=45, ID=46, STRING=47, COMMENT=48, WS=49;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "T__1", "T__2", "ASSIGN", "PLUS", "SUB", "MUL", "DIV", "MOD", 
			"VAR", "ARRAY", "INT", "FLOAT", "CHAR", "BOOL", "EQ", "NEQ", "G", "GE", 
			"L", "LE", "AND", "NOT", "OR", "IF", "THEN", "ELSE", "ENDIF", "FUNC", 
			"ENDFUNC", "READ", "WRITE", "WHILE", "DO", "ENDWHILE", "RETURN", "LPAR", 
			"RPAR", "SEMICOLON", "COLON", "COMMA", "INTVAL", "FLOATVAL", "BOOLVAL", 
			"CHARVAL", "ID", "STRING", "ESC_SEQ", "COMMENT", "WS"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'['", "']'", "'of'", "'='", "'+'", "'-'", "'*'", "'/'", "'%'", 
			"'var'", "'array'", "'int'", "'float'", "'char'", "'bool'", "'=='", "'!='", 
			"'>'", "'>='", "'<'", "'<='", "'and'", "'not'", "'or'", "'if'", "'then'", 
			"'else'", "'endif'", "'func'", "'endfunc'", "'read'", "'write'", "'while'", 
			"'do'", "'endwhile'", "'return'", "'('", "')'", "';'", "':'", "','"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, "ASSIGN", "PLUS", "SUB", "MUL", "DIV", "MOD", 
			"VAR", "ARRAY", "INT", "FLOAT", "CHAR", "BOOL", "EQ", "NEQ", "G", "GE", 
			"L", "LE", "AND", "NOT", "OR", "IF", "THEN", "ELSE", "ENDIF", "FUNC", 
			"ENDFUNC", "READ", "WRITE", "WHILE", "DO", "ENDWHILE", "RETURN", "LPAR", 
			"RPAR", "SEMICOLON", "COLON", "COMMA", "INTVAL", "FLOATVAL", "BOOLVAL", 
			"CHARVAL", "ID", "STRING", "COMMENT", "WS"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	public AslLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "Asl.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\63\u014b\b\1\4\2"+
		"\t\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4"+
		"\13\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22"+
		"\t\22\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31"+
		"\t\31\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t"+
		" \4!\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\4\'\t\'\4(\t(\4)\t)\4*\t*\4+\t"+
		"+\4,\t,\4-\t-\4.\t.\4/\t/\4\60\t\60\4\61\t\61\4\62\t\62\4\63\t\63\3\2"+
		"\3\2\3\3\3\3\3\4\3\4\3\4\3\5\3\5\3\6\3\6\3\7\3\7\3\b\3\b\3\t\3\t\3\n\3"+
		"\n\3\13\3\13\3\13\3\13\3\f\3\f\3\f\3\f\3\f\3\f\3\r\3\r\3\r\3\r\3\16\3"+
		"\16\3\16\3\16\3\16\3\16\3\17\3\17\3\17\3\17\3\17\3\20\3\20\3\20\3\20\3"+
		"\20\3\21\3\21\3\21\3\22\3\22\3\22\3\23\3\23\3\24\3\24\3\24\3\25\3\25\3"+
		"\26\3\26\3\26\3\27\3\27\3\27\3\27\3\30\3\30\3\30\3\30\3\31\3\31\3\31\3"+
		"\32\3\32\3\32\3\33\3\33\3\33\3\33\3\33\3\34\3\34\3\34\3\34\3\34\3\35\3"+
		"\35\3\35\3\35\3\35\3\35\3\36\3\36\3\36\3\36\3\36\3\37\3\37\3\37\3\37\3"+
		"\37\3\37\3\37\3\37\3 \3 \3 \3 \3 \3!\3!\3!\3!\3!\3!\3\"\3\"\3\"\3\"\3"+
		"\"\3\"\3#\3#\3#\3$\3$\3$\3$\3$\3$\3$\3$\3$\3%\3%\3%\3%\3%\3%\3%\3&\3&"+
		"\3\'\3\'\3(\3(\3)\3)\3*\3*\3+\6+\u0103\n+\r+\16+\u0104\3,\6,\u0108\n,"+
		"\r,\16,\u0109\3,\3,\6,\u010e\n,\r,\16,\u010f\3-\3-\3-\3-\3-\3-\3-\3-\3"+
		"-\5-\u011b\n-\3.\3.\3.\3.\3/\3/\7/\u0123\n/\f/\16/\u0126\13/\3\60\3\60"+
		"\3\60\7\60\u012b\n\60\f\60\16\60\u012e\13\60\3\60\3\60\3\61\3\61\3\61"+
		"\3\62\3\62\3\62\3\62\7\62\u0139\n\62\f\62\16\62\u013c\13\62\3\62\5\62"+
		"\u013f\n\62\3\62\3\62\3\62\3\62\3\63\6\63\u0146\n\63\r\63\16\63\u0147"+
		"\3\63\3\63\2\2\64\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f\27\r\31"+
		"\16\33\17\35\20\37\21!\22#\23%\24\'\25)\26+\27-\30/\31\61\32\63\33\65"+
		"\34\67\359\36;\37= ?!A\"C#E$G%I&K\'M(O)Q*S+U,W-Y.[/]\60_\61a\2c\62e\63"+
		"\3\2\t\7\2\"\"\62;C\\aac|\4\2C\\c|\6\2\62;C\\aac|\4\2$$^^\n\2$$))^^dd"+
		"hhppttvv\4\2\f\f\17\17\5\2\13\f\17\17\"\"\2\u0153\2\3\3\2\2\2\2\5\3\2"+
		"\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21"+
		"\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2"+
		"\2\2\2\35\3\2\2\2\2\37\3\2\2\2\2!\3\2\2\2\2#\3\2\2\2\2%\3\2\2\2\2\'\3"+
		"\2\2\2\2)\3\2\2\2\2+\3\2\2\2\2-\3\2\2\2\2/\3\2\2\2\2\61\3\2\2\2\2\63\3"+
		"\2\2\2\2\65\3\2\2\2\2\67\3\2\2\2\29\3\2\2\2\2;\3\2\2\2\2=\3\2\2\2\2?\3"+
		"\2\2\2\2A\3\2\2\2\2C\3\2\2\2\2E\3\2\2\2\2G\3\2\2\2\2I\3\2\2\2\2K\3\2\2"+
		"\2\2M\3\2\2\2\2O\3\2\2\2\2Q\3\2\2\2\2S\3\2\2\2\2U\3\2\2\2\2W\3\2\2\2\2"+
		"Y\3\2\2\2\2[\3\2\2\2\2]\3\2\2\2\2_\3\2\2\2\2c\3\2\2\2\2e\3\2\2\2\3g\3"+
		"\2\2\2\5i\3\2\2\2\7k\3\2\2\2\tn\3\2\2\2\13p\3\2\2\2\rr\3\2\2\2\17t\3\2"+
		"\2\2\21v\3\2\2\2\23x\3\2\2\2\25z\3\2\2\2\27~\3\2\2\2\31\u0084\3\2\2\2"+
		"\33\u0088\3\2\2\2\35\u008e\3\2\2\2\37\u0093\3\2\2\2!\u0098\3\2\2\2#\u009b"+
		"\3\2\2\2%\u009e\3\2\2\2\'\u00a0\3\2\2\2)\u00a3\3\2\2\2+\u00a5\3\2\2\2"+
		"-\u00a8\3\2\2\2/\u00ac\3\2\2\2\61\u00b0\3\2\2\2\63\u00b3\3\2\2\2\65\u00b6"+
		"\3\2\2\2\67\u00bb\3\2\2\29\u00c0\3\2\2\2;\u00c6\3\2\2\2=\u00cb\3\2\2\2"+
		"?\u00d3\3\2\2\2A\u00d8\3\2\2\2C\u00de\3\2\2\2E\u00e4\3\2\2\2G\u00e7\3"+
		"\2\2\2I\u00f0\3\2\2\2K\u00f7\3\2\2\2M\u00f9\3\2\2\2O\u00fb\3\2\2\2Q\u00fd"+
		"\3\2\2\2S\u00ff\3\2\2\2U\u0102\3\2\2\2W\u0107\3\2\2\2Y\u011a\3\2\2\2["+
		"\u011c\3\2\2\2]\u0120\3\2\2\2_\u0127\3\2\2\2a\u0131\3\2\2\2c\u0134\3\2"+
		"\2\2e\u0145\3\2\2\2gh\7]\2\2h\4\3\2\2\2ij\7_\2\2j\6\3\2\2\2kl\7q\2\2l"+
		"m\7h\2\2m\b\3\2\2\2no\7?\2\2o\n\3\2\2\2pq\7-\2\2q\f\3\2\2\2rs\7/\2\2s"+
		"\16\3\2\2\2tu\7,\2\2u\20\3\2\2\2vw\7\61\2\2w\22\3\2\2\2xy\7\'\2\2y\24"+
		"\3\2\2\2z{\7x\2\2{|\7c\2\2|}\7t\2\2}\26\3\2\2\2~\177\7c\2\2\177\u0080"+
		"\7t\2\2\u0080\u0081\7t\2\2\u0081\u0082\7c\2\2\u0082\u0083\7{\2\2\u0083"+
		"\30\3\2\2\2\u0084\u0085\7k\2\2\u0085\u0086\7p\2\2\u0086\u0087\7v\2\2\u0087"+
		"\32\3\2\2\2\u0088\u0089\7h\2\2\u0089\u008a\7n\2\2\u008a\u008b\7q\2\2\u008b"+
		"\u008c\7c\2\2\u008c\u008d\7v\2\2\u008d\34\3\2\2\2\u008e\u008f\7e\2\2\u008f"+
		"\u0090\7j\2\2\u0090\u0091\7c\2\2\u0091\u0092\7t\2\2\u0092\36\3\2\2\2\u0093"+
		"\u0094\7d\2\2\u0094\u0095\7q\2\2\u0095\u0096\7q\2\2\u0096\u0097\7n\2\2"+
		"\u0097 \3\2\2\2\u0098\u0099\7?\2\2\u0099\u009a\7?\2\2\u009a\"\3\2\2\2"+
		"\u009b\u009c\7#\2\2\u009c\u009d\7?\2\2\u009d$\3\2\2\2\u009e\u009f\7@\2"+
		"\2\u009f&\3\2\2\2\u00a0\u00a1\7@\2\2\u00a1\u00a2\7?\2\2\u00a2(\3\2\2\2"+
		"\u00a3\u00a4\7>\2\2\u00a4*\3\2\2\2\u00a5\u00a6\7>\2\2\u00a6\u00a7\7?\2"+
		"\2\u00a7,\3\2\2\2\u00a8\u00a9\7c\2\2\u00a9\u00aa\7p\2\2\u00aa\u00ab\7"+
		"f\2\2\u00ab.\3\2\2\2\u00ac\u00ad\7p\2\2\u00ad\u00ae\7q\2\2\u00ae\u00af"+
		"\7v\2\2\u00af\60\3\2\2\2\u00b0\u00b1\7q\2\2\u00b1\u00b2\7t\2\2\u00b2\62"+
		"\3\2\2\2\u00b3\u00b4\7k\2\2\u00b4\u00b5\7h\2\2\u00b5\64\3\2\2\2\u00b6"+
		"\u00b7\7v\2\2\u00b7\u00b8\7j\2\2\u00b8\u00b9\7g\2\2\u00b9\u00ba\7p\2\2"+
		"\u00ba\66\3\2\2\2\u00bb\u00bc\7g\2\2\u00bc\u00bd\7n\2\2\u00bd\u00be\7"+
		"u\2\2\u00be\u00bf\7g\2\2\u00bf8\3\2\2\2\u00c0\u00c1\7g\2\2\u00c1\u00c2"+
		"\7p\2\2\u00c2\u00c3\7f\2\2\u00c3\u00c4\7k\2\2\u00c4\u00c5\7h\2\2\u00c5"+
		":\3\2\2\2\u00c6\u00c7\7h\2\2\u00c7\u00c8\7w\2\2\u00c8\u00c9\7p\2\2\u00c9"+
		"\u00ca\7e\2\2\u00ca<\3\2\2\2\u00cb\u00cc\7g\2\2\u00cc\u00cd\7p\2\2\u00cd"+
		"\u00ce\7f\2\2\u00ce\u00cf\7h\2\2\u00cf\u00d0\7w\2\2\u00d0\u00d1\7p\2\2"+
		"\u00d1\u00d2\7e\2\2\u00d2>\3\2\2\2\u00d3\u00d4\7t\2\2\u00d4\u00d5\7g\2"+
		"\2\u00d5\u00d6\7c\2\2\u00d6\u00d7\7f\2\2\u00d7@\3\2\2\2\u00d8\u00d9\7"+
		"y\2\2\u00d9\u00da\7t\2\2\u00da\u00db\7k\2\2\u00db\u00dc\7v\2\2\u00dc\u00dd"+
		"\7g\2\2\u00ddB\3\2\2\2\u00de\u00df\7y\2\2\u00df\u00e0\7j\2\2\u00e0\u00e1"+
		"\7k\2\2\u00e1\u00e2\7n\2\2\u00e2\u00e3\7g\2\2\u00e3D\3\2\2\2\u00e4\u00e5"+
		"\7f\2\2\u00e5\u00e6\7q\2\2\u00e6F\3\2\2\2\u00e7\u00e8\7g\2\2\u00e8\u00e9"+
		"\7p\2\2\u00e9\u00ea\7f\2\2\u00ea\u00eb\7y\2\2\u00eb\u00ec\7j\2\2\u00ec"+
		"\u00ed\7k\2\2\u00ed\u00ee\7n\2\2\u00ee\u00ef\7g\2\2\u00efH\3\2\2\2\u00f0"+
		"\u00f1\7t\2\2\u00f1\u00f2\7g\2\2\u00f2\u00f3\7v\2\2\u00f3\u00f4\7w\2\2"+
		"\u00f4\u00f5\7t\2\2\u00f5\u00f6\7p\2\2\u00f6J\3\2\2\2\u00f7\u00f8\7*\2"+
		"\2\u00f8L\3\2\2\2\u00f9\u00fa\7+\2\2\u00faN\3\2\2\2\u00fb\u00fc\7=\2\2"+
		"\u00fcP\3\2\2\2\u00fd\u00fe\7<\2\2\u00feR\3\2\2\2\u00ff\u0100\7.\2\2\u0100"+
		"T\3\2\2\2\u0101\u0103\4\62;\2\u0102\u0101\3\2\2\2\u0103\u0104\3\2\2\2"+
		"\u0104\u0102\3\2\2\2\u0104\u0105\3\2\2\2\u0105V\3\2\2\2\u0106\u0108\4"+
		"\62;\2\u0107\u0106\3\2\2\2\u0108\u0109\3\2\2\2\u0109\u0107\3\2\2\2\u0109"+
		"\u010a\3\2\2\2\u010a\u010b\3\2\2\2\u010b\u010d\7\60\2\2\u010c\u010e\4"+
		"\62;\2\u010d\u010c\3\2\2\2\u010e\u010f\3\2\2\2\u010f\u010d\3\2\2\2\u010f"+
		"\u0110\3\2\2\2\u0110X\3\2\2\2\u0111\u0112\7v\2\2\u0112\u0113\7t\2\2\u0113"+
		"\u0114\7w\2\2\u0114\u011b\7g\2\2\u0115\u0116\7h\2\2\u0116\u0117\7c\2\2"+
		"\u0117\u0118\7n\2\2\u0118\u0119\7u\2\2\u0119\u011b\7g\2\2\u011a\u0111"+
		"\3\2\2\2\u011a\u0115\3\2\2\2\u011bZ\3\2\2\2\u011c\u011d\7)\2\2\u011d\u011e"+
		"\t\2\2\2\u011e\u011f\7)\2\2\u011f\\\3\2\2\2\u0120\u0124\t\3\2\2\u0121"+
		"\u0123\t\4\2\2\u0122\u0121\3\2\2\2\u0123\u0126\3\2\2\2\u0124\u0122\3\2"+
		"\2\2\u0124\u0125\3\2\2\2\u0125^\3\2\2\2\u0126\u0124\3\2\2\2\u0127\u012c"+
		"\7$\2\2\u0128\u012b\5a\61\2\u0129\u012b\n\5\2\2\u012a\u0128\3\2\2\2\u012a"+
		"\u0129\3\2\2\2\u012b\u012e\3\2\2\2\u012c\u012a\3\2\2\2\u012c\u012d\3\2"+
		"\2\2\u012d\u012f\3\2\2\2\u012e\u012c\3\2\2\2\u012f\u0130\7$\2\2\u0130"+
		"`\3\2\2\2\u0131\u0132\7^\2\2\u0132\u0133\t\6\2\2\u0133b\3\2\2\2\u0134"+
		"\u0135\7\61\2\2\u0135\u0136\7\61\2\2\u0136\u013a\3\2\2\2\u0137\u0139\n"+
		"\7\2\2\u0138\u0137\3\2\2\2\u0139\u013c\3\2\2\2\u013a\u0138\3\2\2\2\u013a"+
		"\u013b\3\2\2\2\u013b\u013e\3\2\2\2\u013c\u013a\3\2\2\2\u013d\u013f\7\17"+
		"\2\2\u013e\u013d\3\2\2\2\u013e\u013f\3\2\2\2\u013f\u0140\3\2\2\2\u0140"+
		"\u0141\7\f\2\2\u0141\u0142\3\2\2\2\u0142\u0143\b\62\2\2\u0143d\3\2\2\2"+
		"\u0144\u0146\t\b\2\2\u0145\u0144\3\2\2\2\u0146\u0147\3\2\2\2\u0147\u0145"+
		"\3\2\2\2\u0147\u0148\3\2\2\2\u0148\u0149\3\2\2\2\u0149\u014a\b\63\2\2"+
		"\u014af\3\2\2\2\r\2\u0104\u0109\u010f\u011a\u0124\u012a\u012c\u013a\u013e"+
		"\u0147\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}