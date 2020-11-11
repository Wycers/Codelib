package net.mooctest;

/**
 * The class is responsible for different exceptional cases,
 * that may be caused by user actions while working with {@link TreeNode}
 *
 * @author shell
 * @version 1.0.0
 * @since 1.0.0
 */
public class TreeNodeException extends RuntimeException {

	/**
	 * Constructs a new tree node exception with the specified detail message
	 *
	 * @param message the detail message. The detail message is saved for
	 *                later retrieval by the {@link #getMessage()} method
	 */
	public TreeNodeException(String message) {
		super(message);
	}

	/**
	 * Constructs a new tree node exception with the specified detail message and cause
	 *
	 * @param message the detail message. The detail message is saved for
	 *                later retrieval by the {@link #getMessage()} method
	 * @param  cause the cause (which is saved for later retrieval by the
	 *               {@link #getCause()} method). A {@code null} value is
	 *               permitted, and indicates that the cause is nonexistent
	 *               or unknown
	 */
	public TreeNodeException(String message, Throwable cause) {
		super(message, cause);
	}

}
